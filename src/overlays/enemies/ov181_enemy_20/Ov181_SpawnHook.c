/* Enemy spawn hook: cancel the current action (mode 1), roll a random facing
 * (-1 or +1) into the model field at +0x84, and register the reaction handler.
 *
 * The `+ (pad - pad)` is load-bearing, not noise. mwcc folds a literal `+ 0`
 * away and emits `cmp r0,#0`; the difference of an uninitialised local against
 * itself survives folding and produces the ROM's `adds r0,r0,#0` -- an ADD that
 * sets flags. Same trick as Ov114_StartSidestep, which this family shares a
 * shape with. */

#include "game/enemy_common.h"

extern int RandNextScaled(int range);
extern void SetIndexedSlot(void *self, int script, void *handler);
extern void Ov181_CircleTick(void);

void Ov181_SpawnHook(int *self) {
    int *model = (int *)self[1];
    int pad;

    Ov107_PostTagUpdate((Actor *)(*model), 1, 1);

    *(int *)((char *)model + 0x84) =
        (RandNextScaled(2) + (pad - pad) != 0) ? -1 : 1;

    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), &Ov181_CircleTick);
}
