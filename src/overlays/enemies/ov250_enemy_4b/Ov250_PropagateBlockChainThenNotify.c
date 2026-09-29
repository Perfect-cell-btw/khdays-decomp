/* Post-tick: copies the 44-byte transform down the chain of attached nodes (+0x3c0 -> +0x3b0 ->
 * +0x3ac), then runs the base post-tick. */

#include "game/enemy_common.h"

struct blk11 { int w[11]; };
void Ov250_PropagateBlockChainThenNotify(char *obj) {
    *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x39c) + 4);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x10);
    Ov107_AiState_PostTickBase(obj);
}
