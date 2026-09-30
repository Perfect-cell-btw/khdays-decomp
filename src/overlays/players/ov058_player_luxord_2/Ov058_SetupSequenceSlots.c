/* Set up this enemy's two sequence slots (0x10c each from +0x2cf0 of the shared object) and its
 * flight parameters: every slot is numbered and cleared, the flight timer at +0x2fe4 is zeroed
 * and its speed at +0x2fe8 set to 0x59a (scaled by 1.5 at 20 fps), both slots register the
 * "lu" effect sequence with priority id+7, and the enemy's own emitter at +0x2648 is opened with
 * the 5-word parameter block before the first update. */

#include "nitro/types.h"

typedef struct { int w[5]; } Params;

extern int GetFrameRateMode(void);                                                /* 0: 30 fps, 1: 20 fps, 2: 60 fps */
extern void RegisterSeqAndInit(int a, void *b, int c, int d);                        /* RegisterSeqAndInit */
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern void Ov058_CreateSubObject(char *self);
extern char *data_ov058_020b7e00;
extern char gOv058LuxordLiE0PackPath[];
extern Params data_ov058_020b7b9c;

void Ov058_SetupSequenceSlots(char *self)
{
    Params p;
    char *base = data_ov058_020b7e00;
    char *rig = base + 0xd4 + 0x2c00;
    char *slot;
    int i;

    slot = rig;
    for (i = 0; i < 2; i++) {
        *(u8 *)(slot + 0x19) = 0;
        *(u8 *)(slot + 0x18) = i;
        slot += 0x10c;
    }
    *(int *)(rig + 0x310) = 0;
    *(int *)(rig + 0x314) = 0x59a;
    if (GetFrameRateMode() == 1) {
        *(int *)(rig + 0x314) = (int)(((long long)*(int *)(rig + 0x314) * 0x1800 + 0x800) >> 12);
    }
    slot = rig + 0x1c;
    for (i = 0; i < 2; i++) {
        RegisterSeqAndInit((int)slot, gOv058LuxordLiE0PackPath, 1, *(u8 *)(base + 9) + 7);
        slot += 0x10c;
    }
    p = data_ov058_020b7b9c;
    Ov022_AllocateSlotWithClass((int)(self + 0x248 + 0x2400), *(u8 *)(self + 9), 5, &p);
    Ov058_CreateSubObject(self);
}
