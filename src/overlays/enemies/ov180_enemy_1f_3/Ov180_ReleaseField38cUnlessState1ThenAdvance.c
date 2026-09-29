/* Post-tick: outside action 1 unlinks the attachment at +0x38c; then runs the base post-tick. */

#include "game/enemy_common.h"

void Ov180_ReleaseField38cUnlessState1ThenAdvance(int this_) {
    if (*(signed char *)(this_ + 0x1c6) != 1 && *(int *)(this_ + 0x38c) != 0) {
        Ov107_UnlinkNodeFromOwner((void *)(*(int *)(this_ + 0x38c)));
        *(int *)(this_ + 0x38c) = 0;
    }
    Ov107_AiState_PostTickBase((char *)this_);
}
