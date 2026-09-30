/* Set up this enemy's three sequence slots (0x10c each from +0x2c5c of the shared object) and its
 * flight parameters: the flight timer at +0x2c58 and +0x2d74 are zeroed, the speed at +0x2d70 set
 * to 0xccd (scaled by 1.5 at 20 fps), the three slots register their effect sequences with
 * priority id+7, and the enemy's own emitter at +0x2648 is opened with the 5-word block. */

#include "nitro/types.h"

typedef struct { int w[5]; } Params;

extern int GetFrameRateMode(void);                                                /* 0: 30 fps, 1: 20 fps, 2: 60 fps */
extern void RegisterSeqAndInit(int a, void *b, int c, int d);                        /* RegisterSeqAndInit */
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern char *data_ov096_020bc0c0;
extern char gOv096MarluxiaLiE0PackPath[];
extern char gOv096MarluxiaLiE1PackPath[];
extern char gOv096MarluxiaLiE3PackPath[];
extern Params data_ov096_020bbfe4;

void Ov096_SetupSequenceSlots(char *self)
{
    Params p;
    char *base = data_ov096_020bc0c0;
    char *rig = base + 0x2c50;

    *(int *)(rig + 8) = 0;
    *(int *)(rig + 0x124) = 0;
    *(int *)(rig + 0x120) = 0xccd;
    if (GetFrameRateMode() == 1) {
        *(int *)(rig + 0x120) = (int)(((long long)*(int *)(rig + 0x120) * 0x1800 + 0x800) >> 12);
    }
    RegisterSeqAndInit((int)(rig + 0xc), gOv096MarluxiaLiE0PackPath, 1, *(u8 *)(base + 9) + 7);
    RegisterSeqAndInit((int)(rig + 0x128), gOv096MarluxiaLiE1PackPath, 1, *(u8 *)(base + 9) + 7);
    RegisterSeqAndInit((int)(rig + 0x238), gOv096MarluxiaLiE3PackPath, 1, *(u8 *)(base + 9) + 7);
    p = data_ov096_020bbfe4;
    Ov022_AllocateSlotWithClass((int)(self + 0x248 + 0x2400), *(u8 *)(self + 9), 5, &p);
}
