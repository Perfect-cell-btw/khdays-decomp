/* Rebinds the enemy's five animation tracks: any animation object still attached to a track
 * is removed from the render object at +0x30 and its slot at +0x1c cleared, then every track is
 * bound to the blend table at +0x118 with the given mode and rewound to frame 0. */

#include "nitro/types.h"

extern void NNS_G3dRenderObjRemoveAnmObj(void *renderObj, void *anmObj);                    /* NNS_G3dRenderObjRemoveAnmObj */
extern void BindAnimTrack(void *animation, u16 track, void *table, s16 mode); /* BindAnimTrack */
extern void Anim_SetFrameWrapped(void *animation, int track, int frame);             /* Anim_SetFrameWrapped */

void Ov062_RebindAnimTracks(char *self, int mode)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (((void **)(self + 0x1c))[i] != 0) {
            NNS_G3dRenderObjRemoveAnmObj(self + 0x30, (void *)((void **)(self + 0x1c))[i]);
            *(void **)(self + i * sizeof(void *) + 0x1c) = 0;
        }
        BindAnimTrack(self + 0x10, (u16)i, *(void **)(self + 0x118), mode);
        Anim_SetFrameWrapped(self + 0x10, (u16)i, 0);
    }
}
