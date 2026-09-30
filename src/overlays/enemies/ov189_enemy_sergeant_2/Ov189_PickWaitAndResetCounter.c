/* State step: picks a new random wait between the actor's limits when the last one has run out,
 * posts pose 2, clears the timer and installs the approach step. */

#include "game/enemy_common.h"
#include "game/engine.h"

extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov189_AimApproachAndDispatch(void);

void Ov189_PickWaitAndResetCounter(int self) {
    int *s = *(int **)(self + 4);
    if (s[7] <= 0) {
        int lo = *(int *)(s[0] + 0x224);
        int d = *(int *)(s[0] + 0x228) - lo;
        if (d < 0) d = -d;
        s[7] = lo + RandNextScaled(d + 1);
    }
    Ov107_PostTagUpdate((Actor *)s[0], 2, 1);
    s[6] = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), (void *)&Ov189_AimApproachAndDispatch);
}
