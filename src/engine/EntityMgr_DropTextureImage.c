/* Drops the texture image of entity record `index` (0x184 bytes each from +0xc4 of the entity
 * manager) from main memory; see Model_DropTextureImage. */

#include "game/engine.h"

extern int data_0204c208;

void EntityMgr_DropTextureImage(int index) {
    EntityRecord_DropTextureImage(data_0204c208 + 0xc4 + index * 0x184);
}
