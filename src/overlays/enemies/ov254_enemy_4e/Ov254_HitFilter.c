/* Hit filter of the ov254 actor (+0x1d0): ignored while guarding (+0x1ac bit 0) or already down
 * (+0x21a <= 0), and, while the rider is free (+0x78 of the +0x214 work clear) outside moves 8 and
 * 0xa, for hits without flag 0x2000. The damage (020c89e8) is taken off the +0x21a health (capped
 * by +0x218) and, unless it is a flag-8/0x80 kind-0x80 hit, reaction 0x16d fires with the mode
 * alternating (+0x72) between the special (flag 0x22) or normal pair of data_ov254_020d594c.
 * Knocked out the next move is 3; carrying a rider in move 4 the +0x3c grip loses 1.0; a free
 * actor in move 7 shrugs off the first 3 hits (+0x74), otherwise every third hit (+0x73) the next
 * move is 0xa and 9 before. Returns 0 when ignored, else 1. */

#include "nitro/types.h"

struct ReactionModes { u8 normal[2]; u8 special[2]; };
struct HitFlags { unsigned int low : 16; unsigned int kind : 16; };

extern const struct ReactionModes data_ov254_020d594c;
extern int Ov107_CalcHitDamage(char *self, unsigned int *hit);
extern void Ov107_BuildAndSendUpdate(char *self, int reactionId, u8 mode, int context);

int Ov254_HitFilter(char *self, int source, unsigned int *hit)
{
    u8 normalModes[2] = {
        data_ov254_020d594c.normal[0],
        data_ov254_020d594c.normal[1]
    };
    u8 specialModes[2] = {
        data_ov254_020d594c.special[0],
        data_ov254_020d594c.special[1]
    };
    int *work = *(int **)(self + 0x214);
    int armed;
    int delta;
    int remaining;
    struct HitFlags *flags;

    armed = (work[0x1e] == 0 && *(signed char *)(*work + 0x100 + 0xc6) != 0xa &&
             *(signed char *)(*work + 0x100 + 0xc6) != 8) ? 1 : 0;
    if (*(u16 *)(self + 0x100 + 0xac) & 1) {
        return 0;
    }
    if (*(short *)(self + 0x200 + 0x1a) <= 0) {
        return 0;
    }
    if (armed && ((u16)*hit & 0x2000) == 0) {
        return 0;
    }
    hit[10] = Ov107_CalcHitDamage(self, hit);
    delta = *(short *)(self + 0x200 + 0x1a) - (int)hit[10];
    if (delta < 0) {
        remaining = 0;
    } else {
        remaining = *(short *)(self + 0x200 + 0x18);
        if (delta <= remaining) {
            remaining = delta;
        }
    }
    *(short *)(self + 0x200 + 0x1a) = (short)remaining;
    if ((int)hit[10] > 0) {
        flags = (struct HitFlags *)hit;
        if ((flags->low & 8) == 0 || (flags->low & 0x80) == 0 || flags->kind != 0x80) {
            if ((flags->low & 0x22) != 0) {
                Ov107_BuildAndSendUpdate(self, 0x16d, specialModes[*((u8 *)work + 0x72)], work[2]);
            } else {
                Ov107_BuildAndSendUpdate(self, 0x16d, normalModes[*((u8 *)work + 0x72)], work[2]);
            }
            *((u8 *)work + 0x72) ^= 1;
        }
    }
    if (*(short *)(self + 0x200 + 0x1a) == 0) {
        *(signed char *)(*work + 0x1c7) = 3;
    } else if (work[0x1e] != 0) {
        if (*(signed char *)(*work + 0x100 + 0xc6) == 4) {
            work[0xf] -= 0x1000;
            if (work[0xf] < 0) {
                work[0xf] = 0;
            }
        }
    } else if (armed) {
        if (*(signed char *)(*work + 0x100 + 0xc6) == 7) {
            if (++*((u8 *)work + 0x74) < 4) {
                return 1;
            }
        }
        if (++*((u8 *)work + 0x73) >= 3) {
            *((u8 *)work + 0x73) = 0;
            *(signed char *)(*work + 0x1c7) = 0xa;
        } else {
            *(signed char *)(*work + 0x1c7) = 9;
        }
    }
    return 1;
}
