typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned long long u64;
typedef long long s64;
typedef int BOOL;
typedef int OSIntrMode;
typedef void *OSMessage;
typedef volatile unsigned short vu16;
typedef volatile unsigned int vu32;
typedef volatile unsigned char vu8;

#define NULL ((void *)0)
#define TRUE 1
#define FALSE 0
#define HW_MAIN_MEM 0x02000000




typedef u32 NNSGfdTexKey;
typedef NNSGfdTexKey (*NNSGfdFuncAllocTexVram)(u32 szByte, BOOL is4x4comp, u32 opt);
typedef int (*NNSGfdFuncFreeTexVram)(NNSGfdTexKey key);
extern NNSGfdFuncAllocTexVram data_020423ec;
extern NNSGfdFuncFreeTexVram data_020423f0;
void Party_SetActiveSlots(int idx1st, int idx2nd, int idx3rd, int idx4th, int idx5th);
NNSGfdTexKey func_02010f7c(u32 szByte, BOOL is4x4comp, u32 opt);
int NNS_GfdFreeFrmTexVram(NNSGfdTexKey memKey);
void NNS_GfdResetFrmTexVramState(void);
typedef struct NNSGfdFrmTexVramMnager {
    u16 numSlot;
} NNSGfdFrmTexVramMnager;
extern NNSGfdFrmTexVramMnager data_02047360;
extern void Party_SetActiveSlots (int idx1st, int idx2nd, int idx3rd, int idx4th, int idx5th);
extern void NNS_GfdResetFrmTexVramState (void);
extern NNSGfdTexKey func_02010f7c (u32 szByte, BOOL is4x4comp, u32 opt);
extern int NNS_GfdFreeFrmTexVram (NNSGfdTexKey texKey);

/* NNS_GfdInitFrmTexVramManager -- NitroSystem gfd_FrameTexVramMan.c: NNS_GfdInitFrmTexVramManager. */
void NNS_GfdInitFrmTexVramManager (u16 numSlot, BOOL useAsDefault)
{

    if ( numSlot <= 2 ) {
        Party_SetActiveSlots(4, 3, 2, 0, 1);
    } else {
        Party_SetActiveSlots(4, 3, 0, 2, 1);
    }

    data_02047360.numSlot = numSlot;
    NNS_GfdResetFrmTexVramState();

    if (useAsDefault) {
        data_020423ec = func_02010f7c;
        data_020423f0 = NNS_GfdFreeFrmTexVram;
    }
}
