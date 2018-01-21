/* $Header$ */

/* Purpose: CCM/CCSM/CF conventions */

/* Copyright (C) 1995--2018 Charlie Zender
   This file is part of NCO, the netCDF Operators. NCO is free software.
   You may redistribute and/or modify NCO under the terms of the 
   GNU General Public License (GPL) Version 3 with exceptions described in the LICENSE file */

/* Usage:
   #include "nco_cnv_csm.h" *//* CCM/CCSM/CF conventions */

#ifndef NCO_CNV_CCSM_H
#define NCO_CNV_CCSM_H

/* Standard header files */
#include <stdio.h> /* stderr, FILE, NULL, printf */
#include <string.h> /* strcmp() */

/* 3rd party vendors */
#include <netcdf.h> /* netCDF definitions and C library */
#include "nco_netcdf.h" /* NCO wrappers for netCDF C library */

/* Personal headers */
#include "nco.h" /* netCDF Operator (NCO) definitions */
#include "nco_cln_utl.h" /* Calendar utilities */
#include "nco_lst_utl.h" /* List utilities */
#include "nco_mmr.h" /* Memory management */
#include "nco_sng_utl.h" /* String utilities */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

nco_bool /* O [flg] File obeys CCM/CCSM/CF conventions */
nco_cnv_ccm_ccsm_cf_inq /* O [fnc] Check if file obeys CCM/CCSM/CF conventions */
(const int nc_id); /* I [id] netCDF file ID */

void
nco_cnv_ccm_ccsm_cf_date /* [fnc] Fix date variable in averaged CCSM files */
(const int nc_id, /* I [id] netCDF file ID */
 X_CST_PTR_CST_PTR_Y(var_sct,var), /* I/O [sct] Variables in output file */
 const int nbr_var); /* I [nbr] Number of variables in list */

nm_id_sct * /* O [sct] Extraction list */
nco_cnv_cf_crd_add /* [fnc] Add coordinates defined by CF convention */
(const int nc_id, /* I netCDF file ID */
 nm_id_sct *xtr_lst, /* I/O current extraction list (destroyed) */
 int * const xtr_nbr); /* I/O number of variables in current extraction list */

int                                  /* [rcd] Return code */
nco_cnv_cf_cll_mth_add               /* [fnc] Add cell_methods attributes */
(const int out_id,                   /* I [id] netCDF file ID */
 var_sct * const * const var,        /* I [sct] Variable to reduce (e.g., average) (destroyed) */
 const int var_nbr,                  /* I [nbr] Number of variables to be defined */
 dmn_sct * const * const dmn,        /* I [sct] Dimensions over which to reduce variable */
 const int dmn_nbr,                  /* I [sct] Number of dimensions to reduce variable over */
 const int nco_op_typ,               /* I [enm] Operation type, default is average */
 gpe_sct *gpe,                       /* I [sng] Group Path Editing (GPE) structure */
 const clm_bnd_sct * const cb,       /* I [sct] Climatology bounds structure */
 const trv_tbl_sct * const trv_tbl); /* I [sct] Traversal table */

int /* I [enm] Operation type */
nco_rdc_sng_to_op_typ /* [fnc] Convert operation string to integer */
(const char * const att_op_sng); /* I [sng] Operation string */

const char * /* O [sng] String describing operation type */
nco_op_typ_to_rdc_sng /* [fnc] Convert operation type to string */
(const int nco_op_typ); /* I [enm] Operation type */

#ifdef __cplusplus
} /* end extern "C" */
#endif /* __cplusplus */

#endif /* NCO_CNV_CCSM_H */
