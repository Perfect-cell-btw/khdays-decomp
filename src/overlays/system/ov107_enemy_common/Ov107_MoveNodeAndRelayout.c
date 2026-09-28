/* Ov107_MoveNodeAndRelayout -- move a node to `v` (its translation, +0xa0) and refresh its
 * collision sphere, ov107. Returns what Ov107_UpdateCollisionSphere returns. */

#include "nitro/fx_types.h"

extern void Srt_SetTranslation(void *sub, void *src);
extern int Ov107_UpdateCollisionSphere(void *node);
int Ov107_MoveNodeAndRelayout(char *node, VecFx32 *v) {
    Srt_SetTranslation(node + 0xa0, v);
    return Ov107_UpdateCollisionSphere(node);
}
