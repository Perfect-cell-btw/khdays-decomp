/* Points the entry's +8 at the owner's +0xad byte, clears bit 1 of the owner's flag word at
 * +0x5c, rewrites its four state channels (0, 4, 1, 2) to (0, 0), closes the update and re-arms
 * 020cf14c. */

#include "game/engine.h"

extern void SetIndexedSlot(char *self, int a, void *cb);
extern void Ov277_FinishWhenChildAnimEnds(int);

void Ov277_ResetChannelsB(char *self) {
    char *ctx = *(char **)(self + 4);
    *(int *)(ctx + 8) = *(int *)(ctx + 4) + 0xad;
    *(int *)(*(char **)(ctx + 4) + 0x5c) &= ~2;
    SetSubitemState(*(void **)(ctx + 4), 0, 0, 0);
    SetSubitemState(*(void **)(ctx + 4), 4, 0, 0);
    SetSubitemState(*(void **)(ctx + 4), 1, 0, 0);
    SetSubitemState(*(void **)(ctx + 4), 2, 0, 0);
    RefreshObjectCallbacks(*(void **)(ctx + 4), 0);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), (void *)Ov277_FinishWhenChildAnimEnds);
}
