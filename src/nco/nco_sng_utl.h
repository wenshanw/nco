/* $Header$ */

/* Purpose: String utilities */

/* Copyright (C) 1995--2016 Charlie Zender
   This file is part of NCO, the netCDF Operators. NCO is free software.
   You may redistribute and/or modify NCO under the terms of the 
   GNU General Public License (GPL) Version 3 with exceptions described in the LICENSE file */

/* Usage:
   #include "nco_sng_utl.h" *//* String utilities */

#ifndef NCO_SNG_UTL_H
#define NCO_SNG_UTL_H

#ifdef HAVE_CONFIG_H
# include <config.h> /* Autotools tokens */
#endif /* !HAVE_CONFIG_H */

/* Standard header files */
#include <stdio.h> /* stderr, FILE, NULL, printf */
#include <string.h> /* strcmp() */
#ifdef HAVE_STRINGS_H
# include <strings.h> /* strcasecmp() */
#endif /* !HAVE_STRINGS_H */

#ifdef _MSC_VER
# define NEED_STRCASECMP
# define NEED_STRCASESTR
#endif /* !_MSC_VER */

#if defined(NEED_STRCASECMP) || defined(NEED_STRCASESTR)
# include <ctype.h> /* isalnum(), isdigit(), tolower() */
#endif /* !NEED_STRCASECMP || !NEED_STRCASESTR */

/* 3rd party vendors */

/* Personal headers */
#include "nco_mmr.h" /* Memory management */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#ifdef NEED_ISBLANK
  int /* O [flg] Character is a space or horizontal tab */
  isblank /* [fnc] Is character a space or horizontal tab? */
  (const int chr); /* I [enm] Character to check */
#endif /* !NEED_ISBLANK */
  
#ifdef NEED_STRCASECMP
  int /* O [enm] [-1,0,1] sng_1 [<,=,>] sng_2 */
  strcasecmp /* [fnc] Lexicographical case-insensitive string comparison */
  (const char * const sng_1, /* I [sng] First string */
   const char * const sng_2); /* I [sng] Second string */
  
  int /* O [enm] [-1,0,1] sng_1 [<,=,>] sng_2 */
  strncasecmp /* [fnc] Lexicographical case-insensitive string comparison */
  (const char * const sng_1, /* I [sng] First string */
   const char * const sng_2, /* I [sng] Second string */
   const size_t chr_nbr); /* I [nbr] Compare at most chr_nbr characters */
#endif /* !NEED_STRCASECMP */
  
  /* 20130827 GNU g++ always provides strcasestr(), MSVC never does */
#ifndef __GNUG__
# ifdef NEED_STRCASESTR
  char * /* O [sng] Pointer to sng_2 in sng_1 */
  strcasestr /* [fnc] Lexicographical case-insensitive string search */
  (const char * const sng_1, /* I [sng] First string */
   const char * const sng_2); /* I [sng] Second string */
# endif /* !NEED_STRCASESTR */
#endif /* __GNUG__ */
  
#ifdef NEED_STRDUP
  char * /* O [sng] Copy of input string */
  strdup /* [fnc] Duplicate string */
  (const char * const sng_in); /* I [sng] String to duplicate */
#endif /* !NEED_STRDUP */
  
#ifdef NEED_STRTOLL
  long long int /* O [nbr] String as long long integer */
  strtoll /* [fnc] Convert string to a long long integer */
  (const char * const nptr,
   char ** const endptr,
   const int base);
#endif /* !NEED_STRTOLL */
  
  char * /* O [sng] Parsed command line */
  nco_cmd_ln_sng /* [fnc] Re-construct command line from arguments */
  (const int argc, /* I [nbr] Argument count */
   CST_X_PTR_CST_PTR_CST_Y(char,argv)); /* I [sng] Command line argument values */
  /* char **argv); *//* I [sng] Command line argument values */
  
  char * /* O [sng] CDL-compatible name */
  nm2sng_cdl /* [fnc] Turn variable/dimension/attribute name into legal CDL */
  (const char * const nm_sng); /* I [sng] Name to CDL-ize */
  
  char * /* O [sng] CDL-compatible name */
  nm2sng_fl /* [fnc] Turn file name into legal string for shell commands */
  (const char * const nm_sng); /* I [sng] Name to sanitize */
  
  char * /* O [sng] String containing printable result */
  chr2sng_cdl /* [fnc] Translate C language character to printable, visible ASCII bytes */
  (const char chr_val, /* I [chr] Character to process */
   char * const val_sng); /* I/O [sng] String to stuff printable result into */
  
  char * /* O [sng] String containing printable result */
  chr2sng_xml /* [fnc] Translate C language character to printable, visible ASCII bytes */
  (const char chr_val, /* I [chr] Character to process */
   char * const val_sng); /* I/O [sng] String to stuff printable result into */
  
  int /* O [nbr] Number of escape sequences translated */
  sng_ascii_trn /* [fnc] Replace C language '\X' escape codes in string with ASCII bytes */
  (char * const sng); /* I/O [sng] String to process */
  
  void 
  sng_idx_dlm_c2f /* [fnc] Replace brackets with parentheses in a string */
  (char *sng); /* [sng] String to change from C to Fortran notation */
  
  void /* O [nbr]  */
  sng_trm_trl_zro /* [fnc] Trim zeros trailing decimal point and preceding exponent from floating point string */
  (char * const sng, /* I/O [sng] String to process */
   const int trl_zro_max); /* [nbr] Maximum number of trailing zeros allowed */
  
  kvm_sct /* O [sct] Key-value pair */
  nco_sng2kvm /* [fnc] Parse string into key-value pair */
  (char *sng); /* I [sng] String to parse, including "=" */
  
  char * /* O [sng] Stripped-string */
  nco_sng_strip /* [fnc] Strip leading and trailing white space */
  (char *sng); /* I/O [sng] String to strip */
  
  kvm_sct * /* O [sct] Pointer to free'd kvm list */
  nco_kvm_lst_free /* [fnc] Relinquish dynamic memory from list of kvm structures */
  (kvm_sct *kvm, /* I/O [sct] List of kvm structures */
   const int kvm_nbr); /* I [nbr] Number of kvm structures */
  
  void
  nco_kvm_prn /* [fnc] Print kvm contents */
  (kvm_sct kvm); /* [fnc] kvm to print */
  
#ifdef __cplusplus
} /* end extern "C" */
#endif /* __cplusplus */

#endif /* NCO_SNG_UTL_H */
