/* Runs the model callbacks, then copies the two action resources' transforms into the two models.
 */

#include "game/enemy_common.h"

struct blk11 { int w[11]; };
void Ov262_RefreshAndCopyTwoBlocks(char *obj, int flag) {
    Ov107_AiState_DispatchModelCallbacks(obj, flag);
    *(struct blk11 *)(*(char **)(obj + 0x388) + 0x30) = *(struct blk11 *)(*(char **)(obj + 0x390) + 4);
    *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x30) = *(struct blk11 *)(*(char **)(obj + 0x394) + 4);
}
