/* AI step: when the animation ends, sets stance bit 0x40, posts pose 4, loads its default pose and
 * continues with the fall. */

#include "game/enemy_common.h"

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void Ov264_loadDefaultPoseVecs();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov264_FallStep(void);

void Ov264_stEnterSetFlag40(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)(state[1] + 0xad) != 0) return;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }
    Ov107_PostTagUpdate((Actor *)(*state), 4, 1);
    Ov264_loadDefaultPoseVecs(*state, 1);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov264_FallStep);
}
