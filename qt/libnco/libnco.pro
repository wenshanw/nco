TEMPLATE = lib
TARGET = libnco
CONFIG += staticlib
CONFIG -= qt
CONFIG += debug_and_release

unix:CONFIG( debug, debug|release ) {
        DESTDIR = ./debug
} else {
        DESTDIR = ./release
}

unix {
 DEFINES += HAVE_CONFIG_H
 INCLUDEPATH += ../../
 INCLUDEPATH += /usr/local/include
 INCLUDEPATH += /usr/local
 DEFINES += _BSD_SOURCE
 DEFINES += _POSIX_SOURCE
 LIBS +=
 QMAKE_CFLAGS += -std=c99
}

include (../nco.pri)

SOURCES += ../../src/nco/nco_getopt.c
HEADERS += ../../src/nco/nco_getopt.h
HEADERS += ../../src/nco/libnco.h \
../../src/nco/ncap.h \
../../src/nco/nco.h \
../../src/nco/nco_att_utl.h \
../../src/nco/nco_aux.h \
../../src/nco/nco_bnr.h \
../../src/nco/nco_cln_utl.h \
../../src/nco/nco_cnf_dmn.h \
../../src/nco/nco_cnf_typ.h \
../../src/nco/nco_cnk.h \
../../src/nco/nco_cnv_arm.h \
../../src/nco/nco_cnv_csm.h \
../../src/nco/nco_ctl.h \
../../src/nco/nco_dbg.h \
../../src/nco/nco_dmn_utl.h \
../../src/nco/nco_fl_utl.h \
../../src/nco/nco_grp_trv.h \
../../src/nco/nco_grp_utl.h \
../../src/nco/nco_lmt.h \
../../src/nco/nco_lst_utl.h \
../../src/nco/nco_md5.h \
../../src/nco/nco_mmr.h \
../../src/nco/nco_mpi.h \
../../src/nco/nco_msa.h \
../../src/nco/nco_mss_val.h \
../../src/nco/nco_netcdf.h \
../../src/nco/nco_omp.h \
../../src/nco/nco_pck.h \
../../src/nco/nco_ppc.h \
../../src/nco/nco_prn.h \
../../src/nco/nco_rec_var.h \
../../src/nco/nco_rgr.h \
../../src/nco/nco_rth_flt.h \
../../src/nco/nco_rth_utl.h \
../../src/nco/nco_scl_utl.h \
../../src/nco/nco_scm.h \
../../src/nco/nco_sld.h \
../../src/nco/nco_sng_utl.h \
../../src/nco/nco_srm.h \
../../src/nco/nco_typ.h \
../../src/nco/nco_uthash.h \
../../src/nco/nco_var_avg.h \
../../src/nco/nco_var_lst.h \
../../src/nco/nco_var_rth.h \
../../src/nco/nco_var_scv.h \
../../src/nco/nco_var_utl.h \
../../src/nco/nco_mta.h

SOURCES += ../../src/nco/nco_att_utl.c \
../../src/nco/nco_att_utl.c \
../../src/nco/nco_aux.c \
../../src/nco/nco_bnr.c \
../../src/nco/nco_cln_utl.c \
../../src/nco/nco_cnf_dmn.c \
../../src/nco/nco_cnf_typ.c \
../../src/nco/nco_cnk.c \
../../src/nco/nco_cnv_arm.c \
../../src/nco/nco_cnv_csm.c \
../../src/nco/nco_ctl.c \
../../src/nco/nco_dbg.c \
../../src/nco/nco_dmn_utl.c \
../../src/nco/nco_fl_utl.c \
../../src/nco/nco_grp_trv.c \
../../src/nco/nco_grp_utl.c \
../../src/nco/nco_lmt.c \
../../src/nco/nco_lst_utl.c \
../../src/nco/nco_md5.c \
../../src/nco/nco_mmr.c \
../../src/nco/nco_msa.c \
../../src/nco/nco_mss_val.c \
../../src/nco/nco_netcdf.c \
../../src/nco/nco_omp.c \
../../src/nco/nco_pck.c \
../../src/nco/nco_ppc.c \
../../src/nco/nco_prn.c \
../../src/nco/nco_rec_var.c \
../../src/nco/nco_rgr.c \
../../src/nco/nco_rth_flt.c \
../../src/nco/nco_rth_utl.c \
../../src/nco/nco_scl_utl.c \
../../src/nco/nco_sld.c \
../../src/nco/nco_scm.c \
../../src/nco/nco_sng_utl.c \
../../src/nco/nco_srm.c \
../../src/nco/nco_var_avg.c \
../../src/nco/nco_var_lst.c \
../../src/nco/nco_var_rth.c \
../../src/nco/nco_var_scv.c \
../../src/nco/nco_var_utl.c \
../../src/nco/nco_mta.c

