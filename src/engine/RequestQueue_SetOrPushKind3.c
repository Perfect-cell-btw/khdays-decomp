/* Looks up the head request; if it is already kind 3 the halfword at +2 is overwritten in place,
 * otherwise a new kind-3 request is pushed with the same value. Twelve callers. */

#include "game/engine.h"

extern unsigned char *SoundMgr_PeekQueued(int arg);

void RequestQueue_SetOrPushKind3(int arg) {
    unsigned char *ptr = SoundMgr_PeekQueued(0);

    if (ptr == 0 || ptr[0] != 3) {
        ScriptQueue_Push(3, 0, (unsigned short)arg);
        return;
    }

    *(unsigned short *)(ptr + 2) = arg;
}
