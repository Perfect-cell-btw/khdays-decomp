/* Ov254_RebindSubObjects -- rebind the two sub-objects (+0x384 and +0x388) to fresh resources for
 * this slot. The first takes kind `slot + 1` and the transform block at +0x38c, the second kind
 * `slot + 0x20` and the block at +0x3b0. */

#include "game/enemy_common.h"

extern void Ov254_RebindWorkList(int a, int b, int c, int d);

void Ov254_RebindSubObjects(int obj, int slot, int arg) {
    Ov254_RebindWorkList(*(int *)(obj + 0x384), obj + 0x38c,
                        Ov107_PackTextureHandle((char *)obj, slot + 1), arg);
    Ov254_RebindWorkList(*(int *)(obj + 0x388), obj + 0x3b0,
                        Ov107_PackTextureHandle((char *)obj, slot + 0x20), arg);
}
