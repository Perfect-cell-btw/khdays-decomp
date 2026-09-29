/* Drops the texture image of an entity record's model (+0x10) from main memory; see
 * Model_DropTextureImage. */

#include "game/engine.h"

int EntityRecord_DropTextureImage(int record) {
    return Model_DropTextureImage(record + 0x10);
}
