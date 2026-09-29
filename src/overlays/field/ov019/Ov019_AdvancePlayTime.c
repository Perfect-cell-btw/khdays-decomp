
/* Advance the play-time counter (key 0x20b7) by 2, or 3 in the faster mode; when
 * it reaches the mode's cap (0x3b / 0x77) reset it to 0 and report a rollover
 * (return 1), otherwise store the new value and return 0. */

#include "game/engine.h"

int Ov019_AdvancePlayTime(void) {
    int t = GameState_GetField(0x20b7, 8);
    int mode = GameState_GetField(0x82 << 6, 5);
    int inc;

    if (func_02023c40() == 1) {
        inc = 3;
    } else {
        inc = 2;
    }
    t = t + inc;
    if (mode == 1) {
        if (t >= 0x3b) {
            GameState_SetField(0x20b7, 8, 0);
            return 1;
        }
    } else {
        if (t >= 0x77) {
            GameState_SetField(0x20b7, 8, 0);
            return 1;
        }
    }
    GameState_SetField(0x20b7, 8, (unsigned short)t);
    return 0;
}
