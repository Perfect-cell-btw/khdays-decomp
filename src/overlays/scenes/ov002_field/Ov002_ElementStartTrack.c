
#include "nitro/types.h"
#include "game/engine.h"

extern void Ov002_RebindAnimTracks(short *pAnim, int nTrack, int nFrame);
extern void *func_ov022_020881f8(int nIndex);

/* Start an element's track and, when it is the one that matters, its effect.
 *
 * The two parameters are stored whether or not the element is active. Only an
 * active element gets its track started and enabled, and only track one with the
 * caller asking for it and the owner naming a real effect pair starts that
 * effect on the entry the element points at.
 */
void Ov002_ElementStartTrack(char *pElement, short *pAnim, int nTrack, int nParamA,
                         int nParamB, int bEffect)
{
    char *pOwner;

    pOwner = *(char **)(pElement + 8);

    *(int *)(pElement + 0x2bc) = nParamA;
    *(int *)(pElement + 0x2b8) = nParamB;

    if ((*(u16 *)(pElement + 0x12) & 4) != 0) {
        Ov002_RebindAnimTracks(pAnim, nTrack, 0);
        SceneNode_Enable((u16 *)pAnim);

        if (bEffect != 0 && nTrack == 1
            && *(short *)(pOwner + 0x74) >= 0
            && *(short *)(pOwner + 0x76) >= 0) {
            Slot_Spawn(*(short *)(pOwner + 0x74),
                          *(short *)(pOwner + 0x76),
                          func_ov022_020881f8(*(u8 *)(pElement + 0x2c2)), 0);
        }
    }
}
