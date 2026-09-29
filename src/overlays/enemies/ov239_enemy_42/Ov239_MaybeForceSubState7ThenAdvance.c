/* After a hit (flags 2 or 8), forces action 7 unless in actions 0, 1, 3 or 7; then runs the base
 * post-tick. */

#include "game/enemy_common.h"

void Ov239_MaybeForceSubState7ThenAdvance(int this_) {
    if ((*(unsigned char *)(this_ + 0x1c4) & 0xa) &&
        *(signed char *)(this_ + 0x1c6) != 0 &&
        *(signed char *)(this_ + 0x1c6) != 1 &&
        *(signed char *)(this_ + 0x1c6) != 3 &&
        *(signed char *)(this_ + 0x1c6) != 7) {
        *(signed char *)(this_ + 0x1c7) = 7;
    }
    Ov107_AiState_PostTickBase((char *)this_);
}
