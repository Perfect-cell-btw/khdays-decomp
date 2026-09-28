/* Pillar +0x28 handler: sets stance bit 0, registers in the region and snaps to the source anchor.
 */

#include "nitro/types.h"
#include "nitro/fx.h"

typedef struct Node {
    unsigned char pad0[0x60];
    u16 flags;
    unsigned char pad62[0x18c - 0x62];
    char *source;
    VecFx32 anchor;
} Node;

extern void Ov107_RegisterChildInRegion(Node *node, int region);
extern void Ov107_MoveNodeAndRelayout(Node *node, VecFx32 *anchor);

void Ov107_Pillar_EnterRegion(Node *node, int region) {
    node->flags = (u16)((node->flags & 0xffff00ff) |
                  ((((u32)node->flags << 0x10) >> 0x18 | 1) << 0x18) >> 0x10);
    Ov107_RegisterChildInRegion(node, region);
    if (node->source != 0) {
        node->anchor = *(VecFx32 *)(node->source + 0x48c);
        Ov107_MoveNodeAndRelayout(node, &node->anchor);
    }
}
