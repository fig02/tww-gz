#ifndef D_S_LOGO
#define D_S_LOGO

#include "../dolphin/gctypes.h"
#include "../SSystem/SComponent/c_phase.h"

// This is an incomplete implementation of the real `dScnLogo_c`.
// This is to avoid copying over a long chain of header dependecies from tww decomp

typedef struct dScnLogo_c {
    /* 0x000 */ u8 base[0x1C4 - 0x0];
    /* 0x1C4 */ request_of_phase_process_class mPhs;
    /* 0x1CC */ void* nintendoImg;
    /* 0x1D0 */ void* dolbyImg;
    /* 0x1D4 */ void* progchoiceImg;
    /* 0x1D8 */ void* progyesImg;
    /* 0x1DC */ void* prognoImg;
    /* 0x1E0 */ void* progImg;
    /* 0x1E4 */ void* interImg;
    /* 0x1E8 */ u8 mAction;
    /* 0x1E9 */ u8 mInterFlag;
    /* 0x1EA */ u8 field_0x1ea;
    /* 0x1EB */ u8 field_0x1eb;
    /* 0x1EC */ u16 mTimer;
    /* 0x1EE */ u16 field_0x1ee;
    /* 0x1F0 */ u16 field_0x1f0;
    /* 0x1F2 */ u16 field_0x1f2;
    /* 0x1F4 */ u16 field_0x1f4;
    /* 0x1F8 */ void * field_0x1f8;
    /* 0x1FC */ u32 field_0x1fc;
} dScnLogo_c;

#endif