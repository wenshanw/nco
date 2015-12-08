/* $Header$ */

/* Purpose: Description (definition) of regridding functions */

/* Copyright (C) 2015--2015 Charlie Zender
   This file is part of NCO, the netCDF Operators. NCO is free software.
   You may redistribute and/or modify NCO under the terms of the 
   GNU General Public License (GPL) Version 3 with exceptions described in the LICENSE file */

/* Usage:
   #include "nco_rgr.h" *//* Regridding */

#ifndef NCO_RGR_H
#define NCO_RGR_H

/* Standard header files */
#include <limits.h> /* INT_MAX, LONG_MAX */
#include <math.h> /* sin cos cos sin 3.14159 */
#include <stdio.h> /* stderr, FILE, NULL, printf */
#include <stdlib.h> /* atof, atoi, malloc, getopt */

/* 3rd party vendors */
#include <netcdf.h> /* netCDF definitions and C library */
#include "nco_netcdf.h" /* NCO wrappers for netCDF C library */

/* Personal headers */
#include "nco.h" /* netCDF Operator (NCO) definitions */
#include "nco_mmr.h" /* Memory management */
#include "nco_omp.h" /* OpenMP utilities */
#include "nco_sld.h" /* Swath-Like Data */
#include "nco_sng_utl.h" /* String utilities */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* WIN32 math.h does not define M_PI, needed for dgr2rdn and rdn2dgr */
#ifndef M_PI
# define M_PI        3.14159265358979323846264338327950288   /* pi             */
#endif /* M_PI */

  typedef enum nco_rgr_cmd_typ_enm{ /* [enm] Tempest remap type enum */
    nco_rgr_AAA_nil=0,
    nco_rgr_ApplyOfflineMap,
    nco_rgr_CalculateDiffNorms,
    nco_rgr_GenerateCSMesh,
    nco_rgr_GenerateGLLMetaData,
    nco_rgr_GenerateICOMesh,
    nco_rgr_GenerateLambertConfConicMesh,
    nco_rgr_GenerateOfflineMap,
    nco_rgr_GenerateOverlapMesh,
    nco_rgr_GenerateRLLMesh,
    nco_rgr_GenerateTestData,
    nco_rgr_MeshToTxt,
    nco_rgr_ZZZ_last
  } nco_rgr_cmd_typ;

  typedef enum nco_rgr_mpf_typ_enm{ /* [enm] Mapfile type enum */
    nco_rgr_mpf_nil=0,
    nco_rgr_mpf_ESMF,
    nco_rgr_mpf_SCRIP,
    nco_rgr_mpf_Tempest,
  } nco_rgr_mpf_typ_enm;

  typedef enum nco_rgr_typ_enm{ /* [enm] Regrid type enum */
    nco_rgr_grd_nil=0,
    nco_rgr_grd_1D_to_1D,
    nco_rgr_grd_1D_to_2D,
    nco_rgr_grd_2D_to_1D,
    nco_rgr_grd_2D_to_2D,
  } nco_rgr_typ_enm;

  typedef enum nco_grd_xtn_enm{ /* [enm] Grid-extent enum */
    nco_grd_xtn_nil=0,
    nco_grd_xtn_glb,
    nco_grd_xtn_rgn,
  } nco_grd_xtn_enm;

  /* ESMF: The normalization attribute describes how the conservative weights are calculated, currently this is always set to "destarea" because this is the only option which we currently support. The setting "destarea" means that the conservative weights are calculated by dividing the area of the intersection of the source and destination cells by the area of the destination cell. This is set even when the weights are not conservative in which case it can be ignored. */
  typedef enum nco_rgr_nrm_typ_enm{ /* [enm] Normalization type enum */
    nco_rgr_nrm_nil=0,
    nco_rgr_nrm_fracarea, /* [] Allowed and explained by SCRIP */
    nco_rgr_nrm_destarea, /* [] Only option supported by ESMF, ignored when non-conservative methods used */
    nco_rgr_nrm_none, /* [] Allowed and explained by SCRIP */
    nco_rgr_nrm_unknown, /* Tempest */
  } nco_rgr_nrm_typ_enm;

  /* ESMF: The map_method attribute indicates the interpolation type. The format of the interpolation weight file was developed by a group outside of ESMF, because of its use by utilities outside of ESMF control, the range of some of the meta data is constrained. The map_method is one of these. Because of this constraint, there is no map method corresponding to patch interpolation. A weight file generated with the "patch" interpolation method will have map_method set to "Bilinear remapping".  */
  typedef enum nco_rgr_mth_typ_enm{ /* [enm] Mapfile type enum */
    nco_rgr_mth_nil=0,
    nco_rgr_mth_conservative,
    nco_rgr_mth_bilinear,
    nco_rgr_mth_none,
    nco_rgr_mth_unknown, /* Tempest */
  } nco_rgr_mth_typ_enm;

  typedef struct{ /* nco_mpf_sct */
    /* Contents of SCRIP-generated or -compliant remapping file */
    long int src_grid_size; /* [nbr] Source grid size (src_grid_size or n_a) */
    long int dst_grid_size; /* [nbr] Destination grid size (dst_grid_size or n_b) */
    long int src_grid_corners; /* [nbr] Source grid corners/vertices per gridcell (src_grid_corners or nv_a) */
    long int dst_grid_corners; /* [nbr] Destination grid corners/vertices per gridcell (dst_grid_corners or nv_b) */
    long int src_grid_rank; /* [nbr] Source grid rank */
    long int dst_grid_rank; /* [nbr] Destination grid rank */
    long int num_links; /* [nbr] Number of links (num_links or n_s) */
    long int num_wgts; /* [nbr] Number of weights */
    char *normalization; /* [sng] Normalization type */
    char *map_method; /* [sng] Remapping method */
    char *source_grid; /* [sng] Source grid */
    char *dest_grid; /* [sng] Destination grid */
  } nco_mpf_sct;
  
  void
  nco_bsl_zro /*  Return Bessel function zeros */
  (const int bsl_zro_nbr, /* O [nbr] Order of Bessel function */
   double * const bsl_zro); /* O [frc] Bessel zero */

  int /* O [enm] Return code */
  nco_grd_mk /* [fnc] Create SCRIP-format grid file */
  (rgr_sct * const rgr); /* I/O [sct] Regridding structure */

  int /* O [enm] Return code */
  nco_grd_nfr /* [fnc] Infer SCRIP-format grid file from data file */
  (rgr_sct * const rgr); /* I/O [sct] Regridding structure */

  void
  nco_sph_plg_area /* [fnc] Compute area of spherical polygon */
  (const double * const lat_bnd, /* [dgr] Latitude  boundaries of rectangular grid */
   const double * const lon_bnd, /* [dgr] Longitude boundaries of rectangular grid */
   const long grd_sz_nbr, /* [nbr] Number of gridcells in grid */
   const int bnd_nbr, /* [nbr] Number of bounds in gridcell */
   double * const area_out); /* [sr] Gridcell area */

  void
  nco_lat_wgt_gss /* [fnc] Compute and return sine of Gaussian latitudes and their weights */
  (const int lat_nbr, /* I [nbr] Latitude number */
   double * const lat_sin, /* O [frc] Sine of latitudes */
   double * const wgt_Gss); /* O [frc] Gaussian weights */

  int /* O [enm] Return code */
  nco_rgr_map /* [fnc] Regrid with external weights */
  (rgr_sct * const rgr_nfo, /* I/O [sct] Regridding structure */
   trv_tbl_sct * const trv_tbl); /* I/O [sct] Traversal Table */

  int /* O [enm] Return code */
  nco_rgr_ctl /* [fnc] Control regridding logic */
  (rgr_sct * const rgr_nfo, /* I/O [sct] Regridding structure */
   trv_tbl_sct * const trv_tbl); /* I/O [sct] Traversal Table */

  rgr_sct * /* O [sct] Regridding structure */
  nco_rgr_ini /* [fnc] Initialize regridding structure */
  (const char * const cmd_ln, /* I [sng] Command-line */
   const int in_id, /* I [id] Input netCDF file ID */
   char **rgr_arg, /* [sng] Regridding arguments */
   const int rgr_nbr, /* [nbr] Number of regridding arguments */
   char * const rgr_in, /* I [sng] File containing fields to be regridded */
   char * const rgr_out, /* I [sng] File containing regridded fields */
   char * const rgr_grd_src, /* I [sng] File containing input grid */
   char * const rgr_grd_dst, /* I [sng] File containing destination grid */
   char * const rgr_map, /* I [sng] File containing mapping weights from source to destination grid */
   char * const rgr_var, /* I [sng] Variable for special regridding treatment */
   const double wgt_vld_thr, /* I [frc] Weight threshold for valid destination value */
   char **xtn_var, /* I [sng] Extensive variables */
   const int xtn_nbr); /* I [nbr] Number of extensive variables */
    
  rgr_sct * /* O [sct] Pointer to free'd regridding structure */
  nco_rgr_free /* [fnc] Deallocate regridding structure */
  (rgr_sct *rgr_nfo); /* I/O [sct] Regridding structure */

  int /* O [enm] Return code */
  nco_rgr_tps /* [fnc] Regrid using Tempest library */
  (rgr_sct * const rgr_nfo); /* I/O [sct] Regridding structure */

  const char * /* O [sng] String describing two-dimensional grid-type */
  nco_grd_2D_sng /* [fnc] Convert two-dimensional grid-type enum to string */
  (const nco_grd_2D_typ_enm nco_grd_2D_typ); /* I [enm] Two-dimensional grid-type enum */

  const char * /* O [sng] String describing latitude grid-type */
  nco_grd_lat_sng /* [fnc] Convert latitude grid-type enum to string */
  (const nco_grd_lat_typ_enm nco_grd_lat_typ); /* I [enm] Latitude grid-type enum */

  const char * /* O [sng] String describing longitude grid-type */
  nco_grd_lon_sng /* [fnc] Convert longitude grid-type enum to string */
  (const nco_grd_lon_typ_enm nco_grd_lon_typ); /* I [enm] Longitude grid-type enum */

  const char * /* O [sng] String describing grid extent */
  nco_grd_xtn_sng /* [fnc] Convert two-dimensional grid-extent enum to string */
  (const nco_grd_xtn_enm nco_grd_xtn); /* I [enm] Grid-extent enum */

  const char * /* O [sng] String describing grid conversion */
  nco_rgr_grd_sng /* [fnc] Convert grid conversion enum to string */
  (const nco_rgr_typ_enm nco_rgr_typ); /* I [enm] Grid conversion enum */

  const char * /* O [sng] String describing regridding method */
  nco_rgr_mth_sng /* [fnc] Convert regridding method enum to string */
  (const nco_rgr_mth_typ_enm nco_rgr_mth_typ); /* I [enm] Regridding method enum */

  const char * /* O [sng] String describing mapfile generator */
  nco_rgr_mpf_sng /* [fnc] Convert mapfile generator enum to string */
  (const nco_rgr_mpf_typ_enm nco_rgr_mpf_typ); /* I [enm] Mapfile generator enum */

  const char * /* O [sng] String describing regridding normalization */
  nco_rgr_nrm_sng /* [fnc] Convert regridding normalization enum to string */
  (const nco_rgr_nrm_typ_enm nco_rgr_nrm_typ); /* I [enm] Regridding normalization enum */

  const char * /* O [sng] String containing regridding command and format */
  nco_tps_cmd_fmt_sng /* [fnc] Convert Tempest remap command enum to command string */
  (const nco_rgr_cmd_typ nco_rgr_cmd); /* I [enm] Tempest remap command enum */

  const char * /* O [sng] String containing regridding command name */
  nco_tps_cmd_sng /* [fnc] Convert Tempest remap command enum to command name */
  (const nco_rgr_cmd_typ nco_rgr_cmd); /* I [enm] Tempest remap command enum */

#ifdef __cplusplus
} /* end extern "C" */
#endif /* __cplusplus */

#endif /* NCO_RGR_H */
