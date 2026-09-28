/* Ov023_ReleaseScreenSprites -- Ov023_ReleaseScreenSprites: walk the 0x40 actors of the event scene
 * (0x1a64-byte entries behind the pointer at +0x1daf0) and, for each one belonging to the
 * active screen (+0x87590; Ov023_ActorOnScreen 02088ec0) whose state word (02088eb4) has bit
 * 5, re-arm its sprite id (0202beb8 index / 1, 0202c624); an actor with bit 10 as well is
 * hidden first (02088d18) and the model bound at +0x24 of its resource block (+0x15e0) reset
 * afterwards (02014e2c). */
#include "nitro/types.h"

typedef struct Ov023Actor {
    u8   pad_0000[0x15e0];
    u8  *pResource;           /* 0x15e0 */
    u8   pad_15e4[0x1a64 - 0x15e4];
} Ov023Actor;

typedef struct Ov023Scene {
    u8   pad_00000[0x1daf0];
    Ov023Actor *pActors;      /* 0x1daf0 */
    u8   pad_1daf4[0x87590 - 0x1daf4];
    int  nActiveScreen;       /* 0x87590 */
} Ov023Scene;

typedef struct Ov023SceneRoot {
    int  nField00;            /* 0x00 */
    Ov023Scene *pScene;       /* 0x04 */
} Ov023SceneRoot;

extern int  Ov023_IsActivePanelEntry(Ov023Actor *pActor, int nScreen);   /* Ov023_ActorOnScreen */
extern int  Ov023_Window_GetFlags(Ov023Actor *pActor);                /* the actor's state word */
extern void Ov023_ActorHookJoints(Ov023Actor *pActor);                /* hide the actor */
extern void Entity_SetVisible(u16 nId, int bOn);                        /* arm a sprite id */
extern void Entity_Tick(u16 nId);
extern void NNS_G3dRenderObjResetCallBack(void *pModel);                            /* reset a bound model */
extern Ov023SceneRoot data_ov023_0208a784;

void Ov023_ReleaseScreenSprites(void)
{
    int i;
    int nOffset;
    int nState;
    int bShown;

    i = 0;
    nOffset = 0;
    for (; i < 0x40; i++) {
        if (Ov023_IsActivePanelEntry((Ov023Actor *)((u8 *)data_ov023_0208a784.pScene->pActors + nOffset), data_ov023_0208a784.pScene->nActiveScreen)) {
            nState = Ov023_Window_GetFlags((Ov023Actor *)((u8 *)data_ov023_0208a784.pScene->pActors + nOffset));
            if (nState & 0x20) {
                bShown = nState & 0x400;
                if (bShown) {
                    Ov023_ActorHookJoints((Ov023Actor *)((u8 *)data_ov023_0208a784.pScene->pActors + nOffset));
                }
                Entity_SetVisible(i, 1);
                Entity_Tick(i);
                if (bShown) {
                    NNS_G3dRenderObjResetCallBack(((Ov023Actor *)((u8 *)data_ov023_0208a784.pScene->pActors + nOffset))->pResource + 0x24);
                }
            }
        }
        nOffset += sizeof(Ov023Actor);
    }
}
