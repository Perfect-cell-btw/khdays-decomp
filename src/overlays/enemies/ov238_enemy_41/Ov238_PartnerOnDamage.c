/* Damage handler of the ov238 partner: while alive, the hit's damage (020c89e8, into +0x28) comes off
 * the health (+0x21a, clamped to 0..max); a damaging hit that is not a blocked special plays
 * alternating hurt sounds 0x12e (flag 0x22 picks the first pair). Returns 1 (0 when already down). */
#include "nitro/types.h"
typedef struct { u8 a, b; } Pair2;
typedef struct { unsigned lo : 16; unsigned hi : 16; } HitWord;

extern u8 data_ov238_020d36b0[];
extern int Ov107_CalcHitDamage(char *self, char *hit);
extern void Ov107_BuildAndSendUpdate(char *actor, int bank, int variant, void *at);

int Ov238_PartnerOnDamage(char *self, int attacker, char *hit)
{
    u8 pickB[2];
    u8 pickA[2];
    int *state;
    int hp;

    *(Pair2 *)pickB = *(Pair2 *)&data_ov238_020d36b0[2];
    *(Pair2 *)pickA = *(Pair2 *)&data_ov238_020d36b0[0];
    state = *(int **)(self + 0x214);
    if (*(short *)(self + 0x21a) == 0) {
        return 0;
    }
    *(int *)(hit + 0x28) = Ov107_CalcHitDamage(self, hit);
    hp = *(short *)(self + 0x21a) - *(int *)(hit + 0x28);
    *(short *)(self + 0x21a) = hp < 0 ? 0 : (hp > *(short *)(self + 0x218) ? *(short *)(self + 0x218) : hp);
    if (*(short *)(self + 0x21a) <= 0) {
        *(short *)(self + 0x21a) = 0;
    }
    if (*(int *)(hit + 0x28) > 0) {
        if (!((((HitWord *)hit)->lo & 8) && (((HitWord *)hit)->lo & 0x80) && ((HitWord *)hit)->hi == 0x80)) {
            if (((HitWord *)hit)->lo & 0x22) {
                Ov107_BuildAndSendUpdate(self, 0x12e, pickA[*((u8 *)state + 0x30)], (void *)state[2]);
            } else {
                Ov107_BuildAndSendUpdate(self, 0x12e, pickB[*((u8 *)state + 0x30)], (void *)state[2]);
            }
            *((u8 *)state + 0x30) ^= 1;
        }
    }
    return 1;
}
