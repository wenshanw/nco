/* $Header$ */

/* Purpose: Binary write utilities */

/* Copyright (C) 1995--2016 Charlie Zender
   This file is part of NCO, the netCDF Operators. NCO is free software.
   You may redistribute and/or modify NCO under the terms of the 
   GNU General Public License (GPL) Version 3 with exceptions described in the LICENSE file */

/* Usage:
   #include "nco_bnr.h" *//* Binary write utilities */

#ifndef NCO_BNR_H
#define NCO_BNR_H

/* Standard header files */
#include <stdio.h> /* stderr, FILE, NULL, printf */

/* 3rd party vendors */
#include <netcdf.h> /* netCDF definitions and C library */
#include "nco_netcdf.h" /* NCO wrappers for netCDF C library */

/* Personal headers */
#include "nco.h" /* netCDF Operator (NCO) definitions */
#include "nco_ctl.h" /* Program flow control functions */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

FILE * /* O [fl] Unformatted binary output file handle */
nco_bnr_open /* [fnc] Open unformatted binary data file for writing */
(const char * const fl_bnr); /* [sng] Unformatted binary output file */

int /* [rcd] Return code */
nco_bnr_close /* [fnc] Close unformatted binary data file for writing */
(FILE *fp_bnr, /* I [fl] Unformatted binary output file handle */
 const char * const fl_bnr); /* [sng] Unformatted binary output file */

size_t /* O [nbr] Number of elements successfully written */
nco_bnr_wrt /* [fnc] Write unformatted binary data */
(FILE * const fp_bnr, /* I [fl] Unformatted binary output file handle */
 const char * const var_nm, /* I [sng] Variable name */
 const long var_sz, /* I [nbr] Variable size */
 const nc_type var_typ, /* I [enm] Variable type */
 const void * const void_ptr); /* I [ptr] Data to write */

#ifdef __cplusplus
} /* end extern "C" */
#endif /* __cplusplus */

#endif /* NCO_BNR_H */
