/* Resets the tracked position and movement vectors to zero and starts the child's animation. */

#include "game/engine.h"

struct v3 { int a, b, c; };
extern int data_02041dc8[];

void Ov264_loadDefaultPoseVecs(char *this, int param2) {
    struct v3 buf = *(struct v3 *)data_02041dc8;
    *(struct v3 *)(this + 0x3b4) = buf;
    *(struct v3 *)(this + 0x424) = buf;
    SetSubitemState(*(void **)(this + 0x420), 0, (short)param2, 0);
}
