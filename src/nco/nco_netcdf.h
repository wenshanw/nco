/* $Header$ */

/* Purpose: NCO wrappers for netCDF C library */

/* Copyright (C) 1995--2017 Charlie Zender
   This file is part of NCO, the netCDF Operators. NCO is free software.
   You may redistribute and/or modify NCO under the terms of the 
   GNU General Public License (GPL) Version 3 with exceptions described in the LICENSE file */

/* Usage:
#include "nco_netcdf.h" *//* NCO wrappers for netCDF C library */

/* nco_netcdf.h is (nearly) independent of NCO and does not depend on nco.h
   nco_netcdf.h is an abstraction layer for netcdf.h, plus a few convenience routines
   A similar abstraction layer must exist for each NCO storage backend, e.g., nco_hdf.h

   1. Utility routines, e.g., nco_typ_lng(), c_typ_nm() (routines with no netCDF library counterpart)
   2. File-routine wrappers, e.g., nco_open()
   3. Dimension-routine wrappers, e.g., nco_dimid()
   4. Variable-routine wrappers, e.g., nco_get_var()
   5. Attribute-routine wrappers, e.g., nco_put_att()

   Name Convention: Where appropriate, routine name is identical to netCDF C-library name,
   except nc_ is replaced by nco_

   Argument Ordering Convention: Routines follow same argument order as netCDF C-library
   Additional arguments, such as nc_type, are appended to end of argument list

   Return value convention: Functions return a success/failure code
   Errors in netCDF functions cause NCO wrapper to abort, except *_flg() wrappers
   *_flg() wrappers allow limited, pre-defined, netCDF errors to be non-fatal

   Circularity convention: It is important that none of the error diagnostics
   in these functions call other nco_??? routines because if everything
   starts failing then errors will produce circular diagnostics.
   To ensure this is the case, it is only safe to print diagnostics on
   variables which are supposed to be valid on input. */

#ifndef NCO_NETCDF_H /* Contents have not yet been inserted in current source file */
#define NCO_NETCDF_H

/* Standard header files */
#include <ctype.h> /* isalnum(), isdigit(), tolower() */
#include <stdio.h> /* stderr, FILE, NULL, printf */
#include <stdlib.h> /* strtod, strtol, malloc, getopt, exit */
#include <string.h> /* strcmp() */
#include <assert.h> /* assert() */

/* 3rd party vendors */
#include <netcdf.h> /* netCDF definitions and C library */
#ifdef NC_HAVE_META_H
# include <netcdf_meta.h> /* NC_VERSION_..., NC_HAVE_RENAME_GRP */	 
#endif /* !NC_HAVE_META_H */
#ifdef ENABLE_MPI
# include <mpi.h> /* MPI definitions */
# include <netcdf_par.h> /* Parallel netCDF definitions */
#endif /* !ENABLE_MPI */

/* Personal headers */
#include "nco_typ.h" /* Type definitions, opaque types */

/* NB: 
   nco_netcdf.h does #include nco_typ.h which #defines some forward-compatibility tokens
   nco_netcdf.h does not #include nco.h which #defines some forward-compatibility tokens
   This barrier helps segregate NCO from wrappers
   Re-define minimal sub-set of tokens for nco_netcdf.c as necessary
   This is small exception to the barrier */
#ifndef NC_VERSION_MAJOR
# define NC_VERSION_MAJOR 3
#endif /* !NC_VERSION_MAJOR */
#ifndef NC_VERSION_MINOR
# define NC_VERSION_MINOR 6
#endif /* !NC_VERSION_MINOR */
#ifndef NC_VERSION_PATCH
# define NC_VERSION_PATCH 0
#endif /* !NC_VERSION_PATCH */
#ifndef NC_VERSION_NOTE
# define NC_VERSION_NOTE  "" /* May be blank */
#endif /* !NC_VERSION_NOTE */
#ifndef NC_VERSION
# define NC_VERSION "3.6.0"
#endif /* !NC_VERSION */
  /* Define NC_LIB_VERSION as three-digit number for arithmetic comparisons by CPP */
#ifndef NC_LIB_VERSION
# define NC_LIB_VERSION ( NC_VERSION_MAJOR * 100 + NC_VERSION_MINOR * 10 + NC_VERSION_PATCH )
#endif /* !NC_LIB_VERSION */

#ifndef NC_FORMAT_CLASSIC
# define NC_FORMAT_CLASSIC (1)
#endif
#ifndef NC_FORMAT_64BIT_OFFSET
# define NC_FORMAT_64BIT_OFFSET   (2)
#endif
#ifndef NC_FORMAT_64BIT
# define NC_FORMAT_64BIT (NC_FORMAT_64BIT_OFFSET)
#endif
#ifndef NC_FORMAT_NETCDF4
# define NC_FORMAT_NETCDF4 (3)
#endif
#ifndef NC_FORMAT_NETCDF4_CLASSIC
# define NC_FORMAT_NETCDF4_CLASSIC  (4) /* create netcdf-4 files, with NC_CLASSIC_MODEL. */
#endif
#ifndef NC_FORMAT_64BIT_DATA
# define NC_FORMAT_64BIT_DATA   (5)
#endif
#ifndef NC_ENDIAN_NATIVE
# define NC_ENDIAN_NATIVE 0
#endif
#ifndef NC_ENDIAN_LITTLE
# define NC_ENDIAN_LITTLE 1
#endif
#ifndef NC_ENDIAN_BIG
# define NC_ENDIAN_BIG    2
#endif
#ifndef NC_CONTIGUOUS
# define NC_CONTIGUOUS (1)
#endif
#ifndef NC_NOCHECKSUM
# define NC_NOCHECKSUM 0
#endif
#ifndef NC_NOSHUFFLE
# define NC_NOSHUFFLE 0
#endif

  /* Seven compatibility tokens introduced 20131222 in netCDF 4.3.1-rc7 netcdf.h */
#ifndef NC_FORMAT_UNDEFINED
# define NC_FORMAT_UNDEFINED (0)
#else
# define NC_HAVE_INQ_FORMAT_EXTENDED
#endif
#ifndef NC_FORMAT_NC3
# define NC_FORMAT_NC3     (1)
#endif
#ifndef NC_FORMAT_NC_HDF5
# define NC_FORMAT_NC_HDF5 (2) /*cdf 4 subset of HDF5 */
#endif
#ifndef NC_FORMAT_NC_HDF4
# define NC_FORMAT_NC_HDF4 (3) /* netcdf 4 subset of HDF4 */
#endif
#ifndef NC_FORMAT_PNETCDF
# define NC_FORMAT_PNETCDF (4)
#endif
#ifndef NC_FORMAT_DAP2
# define NC_FORMAT_DAP2    (5)
#endif
#ifndef NC_FORMAT_DAP4
# define NC_FORMAT_DAP4    (6)
#endif

/* Three compatibility tokens from pnetcdf.h introduced to NCO 20140604 
   First actually used 20160114 */
#ifndef NC_64BIT_DATA
# define NC_64BIT_DATA	0x0010 /* CDF-5 format, (64-bit) supported */
#endif
#ifndef NC_FORMAT_CDF5
# define NC_FORMAT_CDF5  5 /* CDF-5 format, with NC_64BIT_DATA. */
#endif
#ifndef NC_FORMAT_64BIT_DATA
# define NC_FORMAT_64BIT_DATA	NC_FORMAT_CDF5
#endif

/* netcdf.h added tokens specifically for DAP in 2012?
   Started annotating these error codes in nco_err_exit() in NCO 4.4.6 in 201409 */
#ifndef NC_EIO
# define NC_EIO          (-68)      /**< Generic IO error */
#endif
#ifndef NC_EACCESS
# define NC_EACCESS      (-77)      /**< Access Failure */
#endif

/* Some netCDF3 stubs for netCDF4 routines need netCDF4-only return codes
   These netCDF4 tokens are never defined in netCDF3-only netcdf.h */
#ifndef HAVE_NETCDF4_H
# ifndef NC_ECANTWRITE
#  define NC_ECANTWRITE    (-103)    /**< Can't write. */
# endif
# ifndef NC_EBADGRPID
#  define NC_EBADGRPID (-116)    /**< Bad group ID. */
# endif
# ifndef NC_ENOGRP
#  define NC_ENOGRP        (-125)    /**< No group found. */
# endif
#endif /* HAVE_NETCDF4_H */

/* netcdf.h replaced NC_EFILLVALUE by case NC_ELATEFILL after about netCDF ~4.2.1 */
#ifdef HAVE_NETCDF4_H
# ifndef NC_EFILLVALUE
#  define NC_EFILLVALUE NC_ELATEFILL
# endif /* NC_EFILLVALUE */
# ifndef NC_ELATEFILL
#  define NC_ELATEFILL NC_EFILLVALUE
# endif /* NC_ELATEFILL */
#else /* !HAVE_NETCDF4_H */
# define NC_ELATEFILL     (-122)    /**< Attempt to define fill value when data already exists. */
# define NC_EFILLVALUE    (-122)    /**< Attempt to define fill value when data already exists. */
#endif /* !HAVE_NETCDF4_H */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Definitions */

/* Begin Utility Routines */
const char * /* O [sng] Native C type */
c_typ_nm /* [fnc] Return string describing native C type */
(const nc_type type); /* I [enm] netCDF type */

const char * /* O [sng] Native CDL type */
cdl_typ_nm /* [fnc] Return string describing native CDL type */
(const nc_type type); /* I [enm] netCDF type */

const char * /* O [sng] Native CDL type suffix */
cdl_typ_sfx /* [fnc] Return suffix string for CDL type */
(const nc_type type); /* I [enm] netCDF type */

const char * /* O [sng] Native XML type */
xml_typ_nm /* [fnc] Return string describing native XML type */
(const nc_type type); /* I [enm] netCDF type */

const char * /* O [sng] Native JSON type */
jsn_typ_nm /* [fnc] Return string describing native JSON type */
(const nc_type type); /* I [enm] netCDF type */

const char * /* O [sng] String describing extended file format */
nco_fmt_xtn_sng /* [fnc] Convert netCDF extended file format enum to string */
(const int fl_fmt_xtn); /* I [enm] netCDF extended file format */

const char * /* O [sng] Native Fortran77 type */
f77_typ_nm /* [fnc] Return string describing native Fortran77 type */
(const nc_type type); /* I [enm] netCDF type */

const char * /* O [sng] Native Fortran90 type */
f90_typ_nm /* [fnc] Return string describing native Fortran90 type */
(const nc_type type); /* I [enm] netCDF type */

void 
nco_dfl_case_nc_type_err /* [fnc] Print error and exit for illegal switch(nc_type) case */
(void);

void 
nco_dfl_case_prg_id_err /* [fnc] Print error and exit for illegal switch(prg_id) case */
(void);

void
nco_dfl_case_generic_err(void); /* [fnc] Print error and exit for illegal switch case */

void
nco_sng_cnv_err /* [fnc] Print error and exit for failed strtol()-type calls */
(const char *cnv_sng, /* I [sng] String to convert */
 const char *sng_cnv_fnc, /* I [sng] Name of function used to convert string */
 const char *err_ptr); /* I [chr] First illegal character in string */
/* end nco_sng_cnv_err() */

void 
nco_err_exit /* [fnc] Print netCDF error message, routine name, then exit */
(const int rcd, /* I [enm] netCDF error code */ 
 const char * const msg); /* I [sng] Supplemental error message */

size_t /* O [B] Native type size */
nco_typ_lng /* [fnc] Convert netCDF type enum to native type size */
(const nc_type nco_typ); /* I [enm] netCDF type */

const char * /* O [sng] String describing type */
nco_typ_sng /* [fnc] Convert netCDF type enum to string */
(const nc_type type); /* I [enm] netCDF type */

const char * /* O [sng] String describing file format */
nco_fmt_sng /* [fnc] Convert netCDF file format enum to string */
(const int fl_fmt); /* I [enm] netCDF file format */

const char * /* O [sng] String describing file format for hidden attributes */
nco_fmt_hdn_sng /* [fnc] Convert netCDF file format enum to string for hidden attributes */
(const int fl_fmt); /* I [enm] netCDF file format */

const char * /* O [sng] String describing endianness for hidden attributes */
nco_ndn_sng /* [fnc] Convert netCDF endianness enum to string for hidden attributes */
(const int flg_ndn); /* I [enm] netCDF endianness */
/* End Utility Routines */

char * /* O [sng] netCDF-compatible name */
nm2sng_nc /* [fnc] Turn group/variable/dimension/attribute name into legal netCDF */
(const char * const nm_sng); /* I [sng] Name to netCDF-ize */

#ifdef ENABLE_MPI
# ifdef HAVE_NETCDF4_H
/* netCDF4 routines defined by Unidata netCDF4 Library libnetcdf.a */
int nco_create_par(const char * const fl_nm,const int cmode,MPI_Comm mpi_cmm,MPI_Info mpi_nfo,int * const nc_id);
int nco_open_par  (const char * const fl_nm,const int  mode,MPI_Comm mpi_cmm,MPI_Info mpi_nfo,int * const nc_id);
int nco_var_par_access(const int nc_id,const int var_id,const int par_access);
# endif /* !HAVE_NETCDF4_H */
# ifdef PNETCDF_EXPOSED_API
/* pnetCDF routines defined by ANL Parallel netCDF Library libpnetcdf.a */
int ncompi_create(MPI_Comm mpi_cmm,const char * const fl_nm,const int cmode,MPI_Info mpi_nfo,int * const nc_id);
int ncompi_open  (MPI_Comm mpi_cmm,const char * const fl_nm,const int omode,MPI_Info mpi_nfo,int * const nc_id);
# endif /* !PNETCDF_EXPOSED_API */
#endif /* !ENABLE_MPI */

/* Begin file-level routines */
int nco_create(const char * const fl_nm,const int cmode,int * const nc_id);
int nco__create(const char * const fl_nm,const int cmode,const size_t sz_ntl,size_t * const bfr_sz_hnt,int * const nc_id);
int nco_open(const char * const fl_nm,const int mode,int * const nc_id);
int nco_open_flg(const char * const fl_nm,const int mode,int * const nc_id);
int nco_open_mem(const char * const fl_nm,const int mode,const size_t sz,void * const void_ptr,int * const nc_id);
int nco__open(const char * const fl_nm,const int mode,size_t * const bfr_sz_hnt,int * const nc_id);
int nco_redef(const int nc_id);
int nco_set_fill(const int nc_id,const int fill_mode,int * const old_mode);
int nco_enddef(const int nc_id);
int nco__enddef(const int nc_id,const size_t hdr_pad);
int nco_sync(const int nc_id);
int nco_abort(const int nc_id);
int nco_close(const int nc_id);
int nco_inq(const int nc_id,int * const dmn_nbr_fl,int * const var_nbr_fl,int * const att_glb_nbr,int * const rec_dmn_id);
#if NEED_NC_INQ_FORMAT
/* Stub for nc_inq_format(), which appeared in netCDF 3.6.1 or 3.6.2 */
int nc_inq_format(int nc_id,int * const fl_fmt);
#endif /* !NEED_NC_INQ_FORMAT */
int nco_inq_format(const int nc_id,int * const fl_fmt);
#ifndef NC_HAVE_INQ_FORMAT_EXTENDED
/* 20131222: Stub for nc_inq_format_extended(), which appeared in netCDF 4.3.1-rc7 */
int nc_inq_format_extended(int nc_id,int * const fl_fmt,int * const mode);
#endif /* !NC_HAVE_INQ_FORMAT_EXTENDED */
int nco_inq_format_extended(const int nc_id,int * const fl_fmt,int * const mode);
int nco_inq_ncid(const int nc_id,const char * const grp_nm,int * const grp_id);
int nco_inq_ncid_flg(const int nc_id,const char * const grp_nm,int * const grp_id);
int nco_inq_ndims(const int nc_id,int * const dmn_nbr_fl);
int nco_inq_nvars(const int nc_id,int * const var_nbr_fl);
int nco_inq_natts(const int nc_id,int * const att_glb_nbr);
int nco_inq_unlimdim(const int nc_id,int * const rec_dmn_id);
int nco_inq_unlimdim_flg(const int nc_id,int * const rec_dmn_id);
int nco_get_chunk_cache(size_t * const sz_byt,size_t * const cnk_nbr_hsh,float * const pmp_fvr_frc);
int nco_set_chunk_cache(const size_t sz_byt,const size_t cnk_nbr_hsh,const float pmp_fvr_frc);
/* End File routines */

/* Begin Group routines (_grp) */
int nco_rename_grp(int grp_id,const char * const grp_nm);
int nco_def_grp(const int nc_id,const char * const grp_nm,int * const grp_id);
int nco_def_grp_flg(const int nc_id,const char * const grp_nm,int * const grp_id);
int nco_inq_dimids(const int nc_id,int * const dmn_nbr,int * const dmn_ids,int flg_prn);
int nco_inq_grpname(const int nc_id,char * const grp_nm);
int nco_inq_grpname_full(const int nc_id,size_t * grp_nm_lng,char * const grp_nm_fll);
int nco_inq_grpname_len(const int nc_id,size_t * const grp_nm_lng);
int nco_inq_grps(const int nc_id,int * const grp_nbr,int * const grp_ids);
int nco_inq_grp_full_ncid(const int nc_id,const char * const grp_nm_fll,int * const grp_id);
int nco_inq_grp_full_ncid_flg(const int nc_id,const char * const grp_nm_fll,int * const grp_id);
int nco_inq_grp_ncid(const int nc_id,const char * const grp_nm,int * const grp_id);
int nco_inq_grp_ncid_flg(const int nc_id,const char * const grp_nm,int * const grp_id);
int nco_inq_grp_parent(const int nc_id,int * const prn_id);
int nco_inq_grp_parent_flg(const int nc_id,int * const prn_id);
int nco_inq_varids(const int nc_id,int * const var_nbr,int * const var_ids);
/* End Group routines */

/* Begin Dimension routines (_dim) */
int nco_def_dim(const int nc_id,const char * const dmn_nm,const long dmn_sz,int * const dmn_id);
int nco_inq_dimid(const int nc_id,const char * const dmn_nm,int * const dmn_id);
int nco_inq_dimid_flg(const int nc_id,const char * const dmn_nm,int * const dmn_id);
int nco_inq_dim(const int nc_id,const int dmn_id,char *dmn_nm,long *dmn_sz);
int nco_inq_dim_flg(const int nc_id,const int dmn_id,char *dmn_nm,long *dmn_sz);
int nco_inq_dimname(const int nc_id,const int dmn_id,char *dmn_nm);
int nco_inq_dimlen(const int nc_id,const int dmn_id,long *dmn_sz);
int nco_rename_dim(const int nc_id,const int dmn_id,const char * const dmn_nm);
int nco_inq_unlimdims(const int nc_id,int *nbr_dmn_ult,int *dmn_ids_ult);
/* End Dimension routines */

/* Begin Variable routines (_var) */
int nco_copy_var(const int nc_in_id,const int var_id,const int nc_out_id);
int nco_def_var(const int nc_id,const char * const var_nm,const nc_type var_typ,const int dmn_nbr,const int * const dmn_id,int * const var_id);
int nco_def_var_chunking(const int nc_id,const int var_id,const int srg_typ,const size_t * const cnk_sz);
int nco_def_var_deflate(const int nc_id,const int var_id,const int shuffle,const int deflate,const int dfl_lvl);
int nco_def_var_fletcher32(const int nc_id,const int var_id,const int chk_typ);
int nco_inq_var(const int nc_id,const int var_id,char * const var_nm,nc_type * const var_typ,int * const dmn_nbr,int * const dmn_id,int * const att_nbr);
int nco_inq_var_chunking(const int nc_id,const int var_id,int * const srg_typ,size_t * const cnk_sz);
int nco_inq_var_deflate(const int nc_id,const int var_id,int * const shuffle,int * const deflate,int * const dfl_lvl);
int nco_inq_var_endian(const int nc_id,const int var_id,int * const ndn_typ);
int nco_inq_var_fill(const int nc_id,const int var_id,int * const fll_nil,void * const fll_val);
int nco_inq_var_fletcher32(const int nc_id,const int var_id,int * const chk_typ);
int nco_inq_var_packing(const int nc_id,const int var_id,int * const packing);
int nco_inq_vardimid(const int nc_id,const int var_id,int * const dmn_id);
int nco_inq_varid(const int nc_id,const char * const var_nm,int * const var_id);
int nco_inq_varid_flg(const int nc_id,const char * const var_nm,int * const var_id);
int nco_inq_varname(const int nc_id,const int var_id,char * const var_nm);
int nco_inq_varnatts(const int nc_id,const int var_id,int * const att_nbr);
int nco_inq_varndims(const int nc_id,const int var_id,int * const dmn_nbr);
int nco_inq_vartype(const int nc_id,const int var_id,nc_type * const var_typ);
int nco_rename_var(const int nc_id,const int var_id,const char * const var_nm);

/* Start _get _put _var */
int nco_get_var(const int nc_id,const int var_id,void * const vp,const nc_type type);
int nco_put_var(const int nc_id,const int var_id,const void * const vp,const nc_type type);
int nco_get_var1(const int nc_id,const int var_id,const long * const srt,void * const vp,const nc_type var_typ);
int nco_put_var1(const int nc_id,const int var_id,const long * const srt,const void * const vp,const nc_type type);
int nco_get_vara(const int nc_id,const int var_id,const long * const srt,const long * const cnt,void * const vp,const nc_type type);
int nco_put_vara(const int nc_id,const int var_id,const long * const srt,const long * const cnt,const void * const vp,const nc_type type);
int nco_get_vars(const int nc_id,const int var_id,const long * const srt,const long * const cnt,const long * const srd,void * const vp,const nc_type type);
int nco_put_vars(const int nc_id,const int var_id,const long * const srt,const long * const cnt,const long * const srd,const void * const vp,const nc_type type);
int nco_get_varm(const int nc_id,const int var_id,const long * const srt,const long * const cnt,const long * const srd,const long * const map,void * const vp,const nc_type type);
int nco_put_varm(const int nc_id,const int var_id,const long * const srt,const long * const cnt,const long * const srd,const long * const map,const void * const vp,const nc_type type);
/* End Variable routines */

/* Begin Attribute routines (_att) */
int nco_inq_att(const int nc_id,const int var_id,const char * const att_nm,nc_type * const att_typ,long * const att_sz);
int nco_inq_att_flg(const int nc_id,const int var_id,const char * const att_nm,nc_type * const att_typ,long * const att_sz); 
int nco_inq_attid(const int nc_id,const int var_id,const char * const att_nm,int * const att_id); 
int nco_inq_attid_flg(const int nc_id,const int var_id,const char * const att_nm,int * const att_id); 
int nco_inq_atttype(const int nc_id,const int var_id,const char * const att_nm,nc_type * const att_typ); 
int nco_inq_attlen(const int nc_id,const int var_id,const char * const att_nm,long * const att_sz); 
int nco_inq_attlen_flg(const int nc_id,const int var_id,const char * const att_nm,long * const att_sz); 
int nco_inq_attname(const int nc_id,const int var_id,const int att_id,char * const att_nm); 
int nco_copy_att(const int nc_id_in,const int var_id_in,const char * const att_nm,const int nc_id_out,const int var_id_out);
int nco_rename_att(const int nc_id,const int var_id,const char * const att_nm,const char * const att_new_nm); 
int nco_del_att(const int nc_id,const int var_id,const char * const att_nm);
int nco_put_att(const int nc_id,const int var_id,const char * const att_nm,const nc_type att_typ,const long att_len,const void * const vp);
int nco_get_att(const int nc_id,const int var_id,const char * const att_nm,void * const vp,const nc_type att_typ);
/* End Attribute routines */

/* Begin libnetcdf prototypes (i.e., for completely new library routines not yet in netcdf.h */
#ifndef NC_HAVE_RENAME_GRP
  int nc_rename_grp(int grp_id,const char * const grp_nm);
#endif /* NC_HAVE_RENAME_GRP */
#if NC_LIB_VERSION >= 440
# include <netcdf_mem.h> /* nc_open_mem() */	 
#else /* 4.4.0 */
  int nc_open_mem(const char * const fl_nm,const int mode,const size_t sz,void * const void_ptr,int * const nc_id);
#endif /* 4.4.0 */

/* Begin netCDF4 stubs */
#ifndef HAVE_NETCDF4_H
  /* Stubs so netCDF4 functions work without protection in netCDF3 environments */
# ifdef NC_HAVE_NEW_CHUNKING_API
  /* Newer, post-200906 netCDF4 API has chk_sz as const
     netcdf.h signals this API with NC_HAVE_NEW_CHUNKING_API as of ~200911 */
  int nc_def_var_chunking(const int nc_id,const int var_id,const int srg_typ,const size_t * const cnk_sz);
# else /* !NC_HAVE_NEW_CHUNKING_API */
  /* Older, pre-200906 netCDF4 API has chk_sz as non-const */
  int nc_def_var_chunking(const int nc_id,const int var_id,const int srg_typ,size_t * const cnk_sz);
# endif /* !NC_HAVE_NEW_CHUNKING_API */
  int nc_inq_var_chunking(const int nc_id,const int var_id,int * const srg_typ,size_t * const cnk_sz);
  int nc_def_var_deflate(const int nc_id,const int var_id,const int shuffle,const int deflate,const int dfl_lvl);
  int nc_def_var_fletcher32(const int nc_id,const int var_id,const int chk_typ);
  int nc_inq_var_deflate(const int nc_id,const int var_id,int * const shuffle, int * const deflate,int * const dfl_lvl);
  int nc_inq_var_endian(const int nc_id,const int var_id,int * const ndn_typ);
  int nc_inq_var_fill(const int nc_id,const int var_id,int * const fll_nil,void * const fll_val);
  int nc_inq_var_fletcher32(const int nc_id,const int var_id,int * const chk_typ);
  int nc_get_chunk_cache(size_t * const sz_byt,size_t * const cnk_nbr_hsh,float * const pmp_fvr_frc);
  int nc_set_chunk_cache(const size_t sz_byt,const size_t cnk_nbr_hsh,const float pmp_fvr_frc);
#endif /* HAVE_NETCDF4_H */
#ifndef HAVE_NETCDF4_H
  int NCO_GET_VAR1_UBYTE(const int nc_id,const int var_id,const size_t *srt,nco_ubyte *ubp);
  int NCO_GET_VAR1_USHORT(const int nc_id,const int var_id,const size_t *srt,nco_ushort *usp);
  int NCO_GET_VAR1_UINT(const int nc_id,const int var_id,const size_t *srt,nco_uint *uip);
  int NCO_GET_VAR1_INT64(const int nc_id,const int var_id,const size_t *srt,nco_int64 *i64p);
  int NCO_GET_VAR1_UINT64(const int nc_id,const int var_id,const size_t *srt,nco_uint64 *ui64p);
  int NCO_GET_VAR1_STRING(const int nc_id,const int var_id,const size_t *srt,nco_string *sngp);
#endif /* HAVE_NETCDF4_H */
#ifndef HAVE_NETCDF4_H
  int NCO_PUT_VAR1_UBYTE(const int nc_id,const int var_id,const size_t *srt,const nco_ubyte *ubp);
  int NCO_PUT_VAR1_USHORT(const int nc_id,const int var_id,const size_t *srt,const nco_ushort *usp);
  int NCO_PUT_VAR1_UINT(const int nc_id,const int var_id,const size_t *srt,const nco_uint *uip);
  int NCO_PUT_VAR1_INT64(const int nc_id,const int var_id,const size_t *srt,const nco_int64 *i64p);
  int NCO_PUT_VAR1_UINT64(const int nc_id,const int var_id,const size_t *srt,const nco_uint64 *ui64p);
  /* 20090712: For unknown reason autobuild sees netcdf4.h header when it should not
     Moreover, it thinks "const nco_string *sng" conflicts with "const char **sng"
     in all nc_put_var?_string() and nc_put_att_string() functions. */
  /*  int NCO_PUT_VAR1_STRING(const int nc_id,const int var_id,const size_t *srt,const nco_string * const sngp);*/
  int NCO_PUT_VAR1_STRING(const int nc_id,const int var_id,const size_t *srt,const char **sngp);
#endif /* HAVE_NETCDF4_H */
#ifndef HAVE_NETCDF4_H
  int NCO_GET_VARA_UBYTE(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,nco_ubyte *ubp);
  int NCO_GET_VARA_USHORT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,nco_ushort *usp);
  int NCO_GET_VARA_UINT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,nco_uint *uip);
  int NCO_GET_VARA_INT64(const int ncrd_id,const int var_id,const size_t *srt,const size_t *cnt,nco_int64 *i64p);
  int NCO_GET_VARA_UINT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,nco_uint64 *ui64p);
  int NCO_GET_VARA_STRING(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,nco_string *sngp);
#endif /* HAVE_NETCDF4_H */
#ifndef HAVE_NETCDF4_H
  int NCO_PUT_VARA_UBYTE(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const nco_ubyte *ubp);
  int NCO_PUT_VARA_USHORT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const nco_ushort *usp);
  int NCO_PUT_VARA_UINT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const nco_uint *uip);
  int NCO_PUT_VARA_INT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const nco_int64 *i64p);
  int NCO_PUT_VARA_UINT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const nco_uint64 *ui64p);
  int NCO_PUT_VARA_STRING(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const char **sngp);
#endif /* HAVE_NETCDF4_H */
#ifndef HAVE_NETCDF4_H
  int NCO_GET_VARS_UBYTE(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,nco_ubyte *ubp);
  int NCO_GET_VARS_USHORT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,nco_ushort *usp);
  int NCO_GET_VARS_UINT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,nco_uint *uip);
  int NCO_GET_VARS_INT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,nco_int64 *i64p);
  int NCO_GET_VARS_UINT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,nco_uint64 *ui64p);
  int NCO_GET_VARS_STRING(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,nco_string *sngp);
#endif /* HAVE_NETCDF4_H */
#ifndef HAVE_NETCDF4_H
  int NCO_PUT_VARS_UBYTE(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const nco_ubyte *ubp);
  int NCO_PUT_VARS_USHORT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd, const nco_ushort *usp);
  int NCO_PUT_VARS_UINT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd, const nco_uint *uip);
  int NCO_PUT_VARS_INT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd, const nco_int64 *i64p);
  int NCO_PUT_VARS_UINT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const nco_uint64 *ui64p);
  int NCO_PUT_VARS_STRING(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const char **sngp);
#endif /* HAVE_NETCDF4_H */
#ifndef HAVE_NETCDF4_H
  int NCO_GET_VARM_UBYTE(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,nco_ubyte *ubp);
  int NCO_GET_VARM_USHORT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,nco_ushort *usp);
  int NCO_GET_VARM_UINT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,nco_uint *uip);
  int NCO_GET_VARM_INT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,nco_int64 *i64p);
  int NCO_GET_VARM_UINT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,nco_uint64 *ui64p);
  int NCO_GET_VARM_STRING(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,nco_string *sngp);
#endif /* HAVE_NETCDF4_H */
#ifndef HAVE_NETCDF4_H
  int NCO_PUT_VARM_UBYTE(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,const nco_ubyte *ubp);
  int NCO_PUT_VARM_USHORT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,const nco_ushort *usp);
  int NCO_PUT_VARM_UINT(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,const nco_uint *uip);
  int NCO_PUT_VARM_INT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,const nco_int64 *i64p);
  int NCO_PUT_VARM_UINT64(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,const nco_uint64 *ui64p);
  int NCO_PUT_VARM_STRING(const int nc_id,const int var_id,const size_t *srt,const size_t *cnt,const ptrdiff_t *srd,const ptrdiff_t *map,const char **sngp);
#endif /* HAVE_NETCDF4_H */
#ifndef HAVE_NETCDF4_H
  /* 20051119: netcdf4 library did not support these until alpha10, still does not support nco_put/get_att_ubyte() */
  int NCO_PUT_ATT_UBYTE(const int nc_id,const int var_id,const char *att_nm,const nc_type att_typ,size_t att_len,const nco_ubyte *ubp);
  int NCO_PUT_ATT_USHORT(const int nc_id,const int var_id,const char *att_nm,const nc_type att_typ,size_t att_len,const nco_ushort *usp);
  int NCO_PUT_ATT_UINT(const int nc_id,const int var_id,const char *att_nm,const nc_type att_typ,size_t att_len,const nco_uint *uip);
  int NCO_PUT_ATT_INT64(const int nc_id,const int var_id,const char *att_nm,const nc_type att_typ,size_t att_len,const nco_int64 *i64p);
  int NCO_PUT_ATT_UINT64(const int nc_id,const int var_id,const char *att_nm,const nc_type att_typ,size_t att_len,const nco_uint64 *ui64p);
  int NCO_PUT_ATT_STRING(const int nc_id,const int var_id,const char *att_nm,const nc_type att_typ,size_t att_len,const char **sngp);
#endif /* HAVE_NETCDF4_H */
#ifndef HAVE_NETCDF4_H
  /* 20051119: netcdf4 library did not support these until alpha10, still does not support nco_put/get_att_ubyte() */
  int NCO_GET_ATT_UBYTE(const int nc_id,const int var_id,const char *att_nm,nco_ubyte *ubp);
  int NCO_GET_ATT_USHORT(const int nc_id,const int var_id,const char *att_nm,nco_ushort *usp);
  int NCO_GET_ATT_UINT(const int nc_id,const int var_id,const char *att_nm,nco_uint *uip);
  int NCO_GET_ATT_INT64(const int nc_id,const int var_id,const char *att_nm,nco_int64 *i64p);
  int NCO_GET_ATT_UINT64(const int nc_id,const int var_id,const char *att_nm,nco_uint64 *ui64p);
  int NCO_GET_ATT_STRING(const int nc_id,const int var_id,const char *att_nm,nco_string *sngp);
#endif /* HAVE_NETCDF4_H */
/* End netCDF4 stubs */

#ifdef __cplusplus
} /* end extern "C" */
#endif /* __cplusplus */

#endif /* NCO_NETCDF_H */
