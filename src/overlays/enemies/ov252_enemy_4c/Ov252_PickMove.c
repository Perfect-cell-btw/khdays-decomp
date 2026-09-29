/* Move pick of the ov252 actor: once the +0x5c rest is over and a target is held (+0x4e4) a roll is
 * drawn; with the +0x4ec shape hidden and move 4 current the next move is 6. When a next move is set
 * while the shape shows and move 4 is current, pose 3 and part motion 2 start, the next move is queued
 * in +0x90 and replaced by 0xc. The rest restarts at 10.0 and 1 is returned (0 when nothing started). */

#include "game/enemy_common.h"

typedef struct { unsigned f : 8; } B8;

extern int RandNextScaled(int bound);

int Ov252_PickMove(int *node)
{
    int *state = (int *)node[1];
    int shown;
    int ok;

    if (state[0x17] <= 0 && *(int *)(*state + 0x4e4) != 0) {
        ok = 1;
        RandNextScaled(0x64);
        shown = ((B8 *)(*(int *)(*state + 0x4ec) + 8))->f & 1;
        ok &= *(signed char *)(*state + 0x1c6) == 4;
        if (shown == 0 && ok) {
            *(unsigned char *)(*state + 0x1c7) = 6;
        }
        if (*(signed char *)(*state + 0x1c7) != -1) {
            if (shown != 0 && *(signed char *)(*state + 0x1c6) == 4) {
                Ov107_PostTagUpdate((Actor *)(*state), 3, 0);
                Ov107_StartAnim(*(int *)(*state + 0x574), 2, 0);
                *((unsigned char *)state + 0x90) = *(signed char *)(*state + 0x1c7);
                *(unsigned char *)(*state + 0x1c7) = 0xc;
            }
            state[0x17] = 0xa000;
            return 1;
        }
    }
    return 0;
}
