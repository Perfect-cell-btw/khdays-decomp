/* Swap the ov252 actor's armour animation to piece `which`: its +0x3a0 slot binds to the +0x384 rig
 * (0203b9ac) and plays with the +0x311 loop bit; every other live piece (+0x39c slot byte not negative)
 * rebinds its slot, replays with its rig-held mode (+0xa8) and resumes at its saved frame `frames[i]`
 * in the +0x88 bank (Anim_SetFrameWrapped). Piece 3 is track 4. */

#include "nitro/types.h"

typedef struct { u8 b0 : 1; } Bit0;
typedef struct { char data[0x24]; } AnimSlot;
struct Ov252Rig { char pad[0x3a0]; AnimSlot slots[4]; };

extern void MainBlob_ResetSlotRows(int rig, AnimSlot *slot);
extern void SetSubitemState(int rig, u16 channel, int a, int b);
extern void Anim_SetFrameWrapped(int bank, int track, int frame);

#define PIECE(i) ((i) == 0 ? 0 : (i) == 1 ? 1 : (i) == 2 ? 2 : 4)

void Ov252_SwapArmourAnim(char *actor, signed char which, int *frames)
{
    int bank = *(int *)(*(int *)(actor + 0x384) + 0x88);
    signed char i;

    MainBlob_ResetSlotRows(*(int *)(actor + 0x384), &((struct Ov252Rig *)actor)->slots[which]);
    SetSubitemState(*(int *)(actor + 0x384), PIECE(which), 0, ((Bit0 *)(actor + 0x311))->b0);
    for (i = 0; i < 4; i++) {
        if (i == which) {
            continue;
        }
        if (*(signed char *)(actor + i + 0x39c) < 0) {
            continue;
        }
        *(AnimSlot **)(*(int *)(actor + 0x384) + 0x8c) = &((struct Ov252Rig *)actor)->slots[i];
        SetSubitemState(*(int *)(actor + 0x384), PIECE(i), 0, *(u8 *)(*(int *)(actor + 0x384) + PIECE(i) + 0xa8));
        Anim_SetFrameWrapped(bank, (u16)(PIECE(i)), frames[i]);
    }
}
