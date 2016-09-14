/* Purpose: netCDF arithmetic processor class methods */

/* Copyright (C) 1995--2016 Charlie Zender
   This file is part of NCO, the netCDF Operators. NCO is free software.
   You may redistribute and/or modify NCO under the terms of the 
   GNU General Public License (GPL) Version 3 with exceptions described in the LICENSE file */

// Standard C++ headers
#ifndef FMC_ALL_CLS_HH
#define FMC_ALL_CLS_HH

#include <math.h>

#include <string>
#include <vector>

#include <antlr/AST.hpp>

#include "ncoTree.hpp"
#include "ncap2_utl.hh"
#include "vtl_cls.hh"
#include "nco_rth_flt.h" /* Float-precision arithmetic, MSVC macros */

#include "sym_cls.hh" // holder for float/double math function pointers
#include "map_srt_tmp.hh" // template -used in srt_cls
#include <assert.h>

  /* Math float prototypes required by AIX, Solaris, but not by Linux, IRIX */
  /* Basic math: acos, asin, atan, cos, exp, fabs, log, log10, sin, sqrt, tan */
  
  /* GNU g++ barfs at these float declartions -- remove if g++ used */
#ifndef __GNUG__
  extern float acosf(float);
  extern float asinf(float);
  extern float atanf(float);
  extern float cosf(float);
  extern float expf(float);
  extern float fabsf(float); /* 20040629: Only AIX may need this */
  extern float logf(float);
  extern float log10f(float);
  extern float rnd_nbrf(float);
  extern float sinf(float);
  extern float sqrtf(float);
  extern float tanf(float);
  
  /* Advanced math: erf, erfc, gamma */
  extern float erff(float);
  extern float erfcf(float);
  extern float gammaf(float);

  /* Hyperbolic trigonometric: acosh, asinh, atanh, cosh, sinh, tanh */
  extern float acoshf(float);
  extern float asinhf(float);
  extern float atanhf(float);
  extern float coshf(float);
  extern float sinhf(float);
  extern float tanhf(float);
  
  /* Basic Rounding: ceil, floor */
  extern float ceilf(float);
  extern float floorf(float);
  
  /* Advanced Rounding: nearbyint, rint, round, trunc */
  extern float nearbyintf(float);
  extern float rintf(float);
  extern float roundf(float);
  extern float truncf(float);
#endif

//Conversion Functions **************************************/
class cnv_cls: public vtl_cls {
private:
  bool _flg_dbg;
public:
    cnv_cls(bool flg_dbg);
    var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};

//Aggregate Functions /***************************************/
class agg_cls: public vtl_cls {
private:
  enum{ PAVG ,PAVGSQR , PMIBS, PMABS, PMEBS, PMAX ,PMIN ,PRMS,
	PRMSSDN, PSQRAVG, PTTL};
  bool _flg_dbg;
public:
  agg_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};

//Utility Functions /****************************************/
class utl_cls: public vtl_cls {
private:
  enum {SET_MISS,CH_MISS,DEL_MISS,GET_MISS,NUM_MISS,HAS_MISS, RAM_WRITE,RAM_DELETE};
   bool _flg_dbg;
public:
  utl_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
  var_sct *is_fnd(bool &is_mtd, std::vector<RefAST> &args_vtr, fmc_cls &fmc_obj, ncoTree &walker);  
  var_sct *get_fnd(bool &is_mtd, std::vector<RefAST> &args_vtr, fmc_cls &fmc_obj, ncoTree &walker);  
};

//Basic Functions /****************************************/
class bsc_cls: public vtl_cls {
private:
  enum {PSIZE,PTYPE,PNDIMS,PEXISTS,PGETDIMS };
   bool _flg_dbg;
public:
  bsc_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
  var_sct *getdims_fnd(bool &is_mtd, std::vector<RefAST> &args_vtr, fmc_cls &fmc_obj, ncoTree &walker);  
};

//Maths Functions /****************************************/
class mth_cls: public vtl_cls {
private:
   bool _flg_dbg;
  std::vector<sym_cls> sym_vtr;
public:
  mth_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};

//Maths2 - Maths functions that take 2 args /*********/
class mth2_cls: public vtl_cls {
private:
   enum {PPOW,PATAN2,PCONVERT};
   bool _flg_dbg;
public:
  mth2_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};

//PDQ Functions /****************************************/
class pdq_cls: public vtl_cls {
private: 
   enum {PREVERSE,PPERMUTE };
   bool _flg_dbg;
public:
  pdq_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};

//Mask Function /****************************************/
class msk_cls: public vtl_cls {
private:
   enum {PMASK1, PMASK_CLIP };
   bool _flg_dbg;
public:
  msk_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};

//Pack Function /****************************************/
class pck_cls: public vtl_cls {
private:
   enum {PPACK, PPACK_BYTE, PPACK_CHAR, PPACK_SHORT, PPACK_INT, PUNPACK,};
   bool _flg_dbg;
public:
  pck_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};

//Sort Function /****************************************/
class srt_cls: public vtl_cls {
private:
  enum {PASORT,PDSORT,PREMAP,PUNMAP,PIMAP };
   bool _flg_dbg;
public:
  srt_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
  var_sct *srt_fnd(bool &is_mtd, std::vector<RefAST> &args_vtr, fmc_cls &fmc_obj, ncoTree &walker);  
  var_sct *mst_fnd(bool &is_mtd, std::vector<RefAST> &args_vtr, fmc_cls &fmc_obj, ncoTree &walker);  
  var_sct *imap_fnd(bool &is_mtd, std::vector<RefAST> &args_vtr, fmc_cls &fmc_obj, ncoTree &walker);  
};

// min/max index functions /****************************************/
// returns the hyperslab indices of the min or max

class agg_idx_cls: public vtl_cls {
private:
  enum { PMIN, PMAX};
   bool _flg_dbg;
public:
  agg_idx_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};



//Unary Function /****************************************/
class unr_cls: public vtl_cls {
private:
   enum {PABS,PSQR };
   bool _flg_dbg;
public:

  unr_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};

//Array Function /****************************************/
class arr_cls: public vtl_cls {
private:
   enum {PARRAY };
   bool _flg_dbg;
public:
  arr_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};

//Array Function /****************************************/
class  bnds_cls: public vtl_cls {
private:
   enum {PBOUNDS };
   bool _flg_dbg;
public:
  bnds_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};



//Bilinear  Interpolation Functions /****************************************/
class bil_cls: public vtl_cls {
private:
  enum {PBIL_ALL,PBIL_ALL_WRP};
   bool _flg_dbg;
public:
  bil_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
  void clc_bil_fnc(var_sct *v_xin, var_sct *v_yin, var_sct *v_din, var_sct *v_xout, var_sct *v_yout, var_sct *v_dout,bool bwrp,std::string sfnm);
  double clc_lin_ipl(double x1,double x2, double x, double Q0,double Q1);
};


//Miscellaneous Function /****************************************/	 
 class misc_cls: public vtl_cls {	 
 private:	 
   enum {PMISC1, PMISC2, PMISC3 };	 
    bool _flg_dbg;	 
 public:	 
   misc_cls(bool flg_dbg);	 
   var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);	 
 	 
 };	 
 	 
// Co-ord class /*********************************************************/
class cod_cls: public vtl_cls {
private:
   enum {PCOORD };
   bool _flg_dbg;
public:
  cod_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};


// var list class /*********************************************************/
class vlist_cls: public vtl_cls {
private:
  enum {PJOIN,PPUSH,PGET_VARS_IN,PGET_VARS_OUT,PATOI,PATOL};
   bool _flg_dbg;
public:
  vlist_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
  var_sct *push_fnd(bool &is_mtd, std::vector<RefAST> &args_vtr, fmc_cls &fmc_obj, ncoTree &walker);  
  var_sct *get_fnd(bool &is_mtd, std::vector<RefAST> &args_vtr, fmc_cls &fmc_obj, ncoTree &walker);  
  var_sct *atoi_fnd(bool &is_mtd, std::vector<RefAST> &args_vtr, fmc_cls &fmc_obj, ncoTree &walker);  
  var_sct *join_fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};


// derived aggregate Functions /***************************************/
class aggd_cls: public vtl_cls {
private:
  enum{ PWVARIANCE};
  bool _flg_dbg;
public:
  aggd_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};


// print  Function family    /***************************************/
class print_cls: public vtl_cls {
private:
  enum{ PPRINT, PSPRINT,PSNPRINT};
  bool _flg_dbg;
public:
  print_cls(bool flg_dbg);
  var_sct *fnd(RefAST expr, RefAST fargs,fmc_cls &fmc_obj, ncoTree &walker);
};





#endif // FMC_ALL_CLS_HH
