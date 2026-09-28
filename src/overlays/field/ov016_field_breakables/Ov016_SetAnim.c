/* Stores the animation type and parameters and, when visible, rebinds and enables it. */

#include "nitro/types.h"

extern void Ov002_RebindAnimTracks(short *pAnim, int nBlend, int nFrame);
extern void SceneNode_Enable(u16 *p);

void Ov016_SetAnim(char *self, int type, int field624, int field620) {
    u16 flags;
    short *pAnim;

    *(char *)(self + 0x61e) = (char)type;
    *(int *)(self + 0x624) = field624;
    *(int *)(self + 0x620) = field620;

    flags = *(u16 *)(self + 0x12);
    pAnim = (short *)(self + 0x4a8);
    if ((flags & 4) != 0) {
        if ((flags & 4) != 0) {
            Ov002_RebindAnimTracks(pAnim,
                                 *(signed char *)(self + 0x61e),
                                 *(int *)(self + 0x620));
            SceneNode_Enable((u16 *)pAnim);
        }
    }
}
