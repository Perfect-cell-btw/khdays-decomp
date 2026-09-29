/* Copies the 44-byte transform block and hands over to the follow-up.
 *
 * ★ The eleven-word ldm/stm block copy IS reachable from C: it is a plain struct
 * assignment of a `struct { int w[11]; }`.  mwcc emits exactly the ROM's
 * `ldm!{r0-r3} / stm!{r0-r3}` twice plus `ldm{r0-r2} / stm{r0-r2}`.  This retires the
 * "11-word block-copy" class that had five functions parked against it. */

#include "game/enemy_common.h"

typedef struct { int w[11]; } Blk44;

extern void Ov107_ProcessObjectTick(char *self, int flag);

void Ov254_Pillar_TickFollowOwner(char *self, int flag) {
    Ov107_MoveNodeAndRelayout((Actor *)self, (VecFx32 *)(*(char **)(self + 0x390) + 0xb0));
    Ov107_ProcessObjectTick(self, flag);
    *(Blk44 *)(*(char **)*(char **)(self + 0x388) + 0x10) = *(Blk44 *)(self + 0xa0);
}
