/*
 *  Twstat.h  --  functions to get informations about libTw objects.
 *
 *  Copyright (C) 2001 by Massimiliano Ghilardi
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 */

#ifndef _TW_STAT_H
#define _TW_STAT_H

#include <stdarg.h>
#include <Tw/Twtypes.h>

#define TWS__CAT(a,b) a##b
#define TWS_CAT(a,b) TWS__CAT(a,b)

#define TWS__STR(a) #a
#define TWS_STR(a) TWS__STR(a)

/* the following are hardcoded in socket.c, libTw.c and libTw ABI, don't change! */
#define TWS_void   0
#define TWS_byte   1
#define TWS_num    1
#define TWS_dat    2
#define TWS_udat   2
#define TWS_ldat   3
#define TWS_uldat  3
#define TWS_hwcol  4
#define TWS_time_t 5
#define TWS_frac_t 6
#define TWS_hwfont 7
#define TWS_hwattr 8
#define TWS_highest 9
#define TWS_tobj   0xFF
#define TWS_obj    0xFF
#define TWS_last   0xFF
#define TWS_vec    0x100 /* this is used as TWS_vec | TWS_<some other type> */
#define TWS_vecW   0x200 /* this is used as TWS_vecW | TWS_<some other type> */

/* the following are hardcoded in libTw ABI, don't change! */
#define TWS_base_CHR   '\x00'
#define TWS_void_STR   "\xFE" /* "\xFF" would conflict with TWS_obj */
#define TWS_byte_STR   "\x01"
#define TWS_num_STR    "\x01"
#define TWS_dat_STR    "\x02"
#define TWS_udat_STR   "\x02"
#define TWS_ldat_STR   "\x03"
#define TWS_uldat_STR  "\x03"
#define TWS_hwcol_STR  "\x04"
#define TWS_time_t_STR "\x05"
#define TWS_frac_t_STR "\x06"
#define TWS_hwfont_STR "\x07"
#define TWS_hwattr_STR "\x08"


#define TWS_field_byte   val._
#define TWS_field_num    val._
#define TWS_field_dat    val._
#define TWS_field_udat   val._
#define TWS_field_ldat   val._
#define TWS_field_uldat  val._
#define TWS_field_hwcol  val._
#define TWS_field_hwfont val._
#define TWS_field_hwattr val._
#define TWS_field_time_t val._
#define TWS_field_frac_t val._
#define TWS_field_tobj   val._

#define TWS_field_scalar val._

#define TWS_field_obj    val.o
#define TWS_field_vecV   val.vec.V
#define TWS_field_vecVV  val.vecV.V
#define TWS_field_vecL   val.vec.L

#ifdef __cplusplus
  extern "C" {
#endif
#if 0
  }
#endif

typedef union s_tsval {
    tlargest _;
#ifdef obj
    obj    o;
#endif
    struct {
	TW_CONST void *V;
	uldat L;
    } vec;
    struct {
	void *V;
	uldat L;
    } vecV;
} tsval;

typedef struct s_tsfield {
    udat hash;
    udat type;
    tsval val;
} *tsfield;

typedef struct s_tslist {
    udat N;
    udat flags;
    struct s_tsfield TSF[1];
} *tslist;

tlargest Tw_Stat (     tdisplay TwD, tobj Id, udat h);
tslist   Tw_StatL(     tdisplay TwD, tobj Id, udat hN, ...);
tslist   Tw_StatA(     tdisplay TwD, tobj Id, udat hN, TW_CONST udat *h);
tslist   Tw_StatV(     tdisplay TwD, tobj Id, udat hN, va_list h);
tslist   Tw_CloneStat( tdisplay TwD, tobj Id, udat hN, ...);
tslist   Tw_CloneStatA(tdisplay TwD, tobj Id, udat hN, TW_CONST udat *h);
tslist   Tw_CloneStatV(tdisplay TwD, tobj Id, udat hN, va_list h);
void     Tw_DeleteStat(tdisplay TwD, tslist TSL);
tsfield  Tw_FindStat(  tdisplay TwD, tslist TSL, udat hash);
void     Tw_ChangeField(tdisplay TwD, tobj Obj, udat field, uldat CLEARMask, uldat XORMask);



#define TwStat(           Id,       h)		Tw_Stat(      Tw_DefaultD, Id, h)

/* GCC has variable-arguments macros (they are ugly and tricky, but work) */
#ifdef __GNUC__
# define TwStatL(         Id,       hN...)	Tw_StatL(     Tw_DefaultD, Id ,##hN)
#else
 tslist  TwStatL(    tobj Id, uldat hN, ...);
#endif
#define TwStatA(          Id,       hN, h)	Tw_StatA(     Tw_DefaultD, Id, hN, h)
#define TwStatV(          Id,       hN, h)	Tw_StatV(     Tw_DefaultD, Id, hN, h)

#ifdef __GNUC__
# define TwCloneStatL(    Id,       hN...)	Tw_CloneStatL(Tw_DefaultD, Id ,##hN)
#else
 tslist TwCloneStatL(tobj Id, uldat hN, ...);
#endif
#define TwCloneStatA(     Id,       hN, h)	Tw_CloneStatA(Tw_DefaultD, Id, hN, h)
#define TwCloneStatV(     Id,       hN, h)	Tw_CloneStatV(Tw_DefaultD, Id, hN, h)
#define TwDeleteStat(TSL)			Tw_DeleteStat(Tw_DefaultD, TSL)
#define TwFindStat(  TSL, hash)			Tw_FindStat(  Tw_DefaultD, TSL, hash)
#define TwChangeField(Obj, field, CLEARMask, XORMask) \
	Tw_ChangeField(Tw_DefaultD, Obj, field, CLEARMask, XORMask)


#ifdef __cplusplus
}
#endif

#endif /* _TW_STAT_H */

