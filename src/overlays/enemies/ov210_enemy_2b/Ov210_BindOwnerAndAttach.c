/* Store the owner (param_2) at +4; if a spawn position (param_3) is given, copy it to
 * +0x20 and run the ov107 attach. */

#include "nitro/fx_types.h"
#include "game/enemy_common.h"

void Ov210_BindOwnerAndAttach(int param_1, int param_2, int param_3) {
    *(int *)(param_1 + 4) = param_2;
    if (param_3 == 0) return;
    *(VecFx32 *)(param_1 + 0x20) = *(VecFx32 *)param_3;
    Ov107_MoveNodeAndRelayout((Actor *)(*(int *)param_1), (VecFx32 *)(param_1 + 0x20));
}
