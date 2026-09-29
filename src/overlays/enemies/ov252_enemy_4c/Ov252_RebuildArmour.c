/* Rebuild the ov252 actor's armour models for damage `level`: the current armour's (+0x310) other pieces
 * record their animation frames (020cd620), every bound slot is released (0202a440) and the +0x88 bank
 * resets, each live piece (+0x39c) rebinds to its model record (020c9440, id + 1), the armour's
 * animation resumes (020cd6b0: piece 1 for 0x2f-0x30, 2 for 0x31-0x34, 3 for 0x35-0x38, else 0), and the
 * five body parts (+0x388..+0x398, slots +0x430..+0x4c0) take their level poses (020cd5a8) below 0x2f
 * (only the first at 0x2e). */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef struct { u8 b0 : 1; } Bit0;
typedef struct { char pad0[0xc]; int bound; char pad10[0x14]; } AnimSlot;
struct Ov252Rig { char pad[0x3a0]; AnimSlot slots[4]; };

extern void Ov252_FetchArmourRecords(char *actor, signed char which, int *frames);
extern void FreeAllResourceTables(AnimSlot *slot);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void Snd_RegisterSeqAndBind(AnimSlot *slot, int bank, void *record, int d);
extern void Ov252_SwapArmourAnim(char *actor, signed char which, int *frames);
extern void Ov252_RebindWorkList(int rig, char *list, void *pose, int flag);

/* Model record of armour kind `k`; every range (piece 0 below 0x2f, 1 below 0x31, 2 below 0x35, 3)
 * maps to k + 1. */
static inline int ArmourModelId(int k)
{
    return k < 0x2f ? k + 1 : k < 0x31 ? k + 1 : k < 0x35 ? k + 1 : k + 1;
}

void Ov252_RebuildArmour(char *actor, int level)
{
    int bank = *(int *)(*(int *)(actor + 0x384) + 0x88);
    int frames[4] = {0};
    int i;
    signed char k;

    k = *(signed char *)(actor + 0x310);
    if (k < 0x2f) {
        Ov252_FetchArmourRecords(actor, 0, frames);
    } else if (k < 0x31) {
        Ov252_FetchArmourRecords(actor, 1, frames);
    } else if (k < 0x35) {
        Ov252_FetchArmourRecords(actor, 2, frames);
    } else {
        Ov252_FetchArmourRecords(actor, 3, frames);
    }
    for (i = 0; i < 4; i++) {
        if (((struct Ov252Rig *)actor)->slots[i].bound != 0) {
            FreeAllResourceTables(&((struct Ov252Rig *)actor)->slots[i]);
        }
    }
    NNS_G3dRenderObjInit(bank + 0x20, *(int *)(bank + 0x78));
    for (i = 0; i < 4; i++) {
        k = *(signed char *)(actor + i + 0x39c);
        if (k >= 0) {
            Snd_RegisterSeqAndBind(&((struct Ov252Rig *)actor)->slots[i], bank, Ov107_PackTextureHandle(actor, ArmourModelId(k)), 0xc);
        }
    }
    switch (*(signed char *)(actor + 0x310)) {
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
        Ov252_SwapArmourAnim(actor, 3, frames);
        break;
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
        Ov252_SwapArmourAnim(actor, 2, frames);
        break;
    case 0x2f:
    case 0x30:
        Ov252_SwapArmourAnim(actor, 1, frames);
        break;
    default:
        Ov252_SwapArmourAnim(actor, 0, frames);
        break;
    }
    if (level >= 0x2f) {
        return;
    }
    Ov252_RebindWorkList(*(int *)(actor + 0x388), actor + 0x430, Ov107_PackTextureHandle(actor, level + 0x3b),
                        ((Bit0 *)(actor + 0x311))->b0);
    if (level >= 0x2e) {
        return;
    }
    Ov252_RebindWorkList(*(int *)(actor + 0x38c), actor + 0x454, Ov107_PackTextureHandle(actor, level + 0x6b),
                        ((Bit0 *)(actor + 0x311))->b0);
    Ov252_RebindWorkList(*(int *)(actor + 0x390), actor + 0x478, Ov107_PackTextureHandle(actor, level + 0x9a),
                        ((Bit0 *)(actor + 0x311))->b0);
    Ov252_RebindWorkList(*(int *)(actor + 0x394), actor + 0x49c, Ov107_PackTextureHandle(actor, level + 0xc9),
                        ((Bit0 *)(actor + 0x311))->b0);
    Ov252_RebindWorkList(*(int *)(actor + 0x398), actor + 0x4c0, Ov107_PackTextureHandle(actor, level + 0xf8),
                        ((Bit0 *)(actor + 0x311))->b0);
}
