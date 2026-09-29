/* Adds to the mission tally for a player's value, scaled by the player's step (5% per step, full at
 * 10) outside replay. */

#include "game/engine.h"

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
#pragma opt_lifetimes on

extern void Ov002_AddMissionTally(int slot, int kind, int value);
extern unsigned char data_0204be04;

struct PlayerScale020889cc {
    unsigned char _pad0000[0x2ab3];
    unsigned char step;
};

void Ov022_SetPlayerScale(int player, int value) {
    struct PlayerScale020889cc *base;
    register int quotient;
    int step;
    unsigned int scaled;
    register unsigned int packedHigh;

    if (data_0204be04 != 0) {
        return;
    }
    base = (struct PlayerScale020889cc *)GetEntryField20ByIndex(player);
    if (base == 0) {
        return;
    }
    if (value <= 0) {
        return;
    }

    quotient = (value << 12) / 100;
    step = base->step - 1;
    if (step < 0) {
        step = 0;
    }
    if (step >= 10) {
        step = 100;
        quotient *= step;
        packedHigh = value << 16;
    } else {
        step = step * 5;
        quotient *= step;
        packedHigh = value << 16;
    }
    scaled = quotient + 0xfff;
    scaled <<= 4;
    Ov002_AddMissionTally(0, 2, packedHigh | (scaled >> 16));
}
