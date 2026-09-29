/* Copies the actor's transform to its two models, then runs the base post-tick. */

#include "game/enemy_common.h"

struct blk11 { int w[11]; };
void Ov293_CopyBlockToTwoNodesThenNotify(char *obj) {
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x390) + 4);
    *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x390) + 4);
    Ov107_AiState_PostTickBase(obj);
}
