/* Ov023_ActorPlayMotion -- Ov023_ActorPlayMotion: play a motion on one of an actor's tracks,
 * replacing whatever was queued there.  A paused animation (bit 2 of the entity's halfword
 * at +4) is resumed first: its held handle (+0x10) is unhooked (02014dc4), the saved track
 * (+0xce), speed (+0xdc = 1.0) and handle (+0xd8) restored and bit 2 dropped.  A motion name
 * ending in ".p2" opens the actor's motion text (+0x1a24, 02024ee8 heap 0xd) when not yet
 * open.  The track's queue head (+0x538) takes the frame, blend and name and the track starts
 * (Ov023_ActorStartMotion 02087298); the rest of that track's queue is emptied (frames -1).
 * With no track holding a motion afterwards flag bit 9 (+0x1a28) is dropped, and on track 0
 * with bit 7 the model is reset (02089174). */

#include "nitro/types.h"

typedef struct Ov023Anim {  /* at +4 of the entity */
    u16  wFlags;              /* 0x00 */
    u16  wTrack;              /* 0x02 */
    u8   pad_04[8];
    int  nHandle;             /* 0x0c */
    u8   pad_10[0x10];
    u32  nControl;            /* 0x20 */
    u8   pad_24[0xca - 0x24];
    s16  nSavedTrack;         /* 0xca */
    u8   pad_cc[8];
    int  nSavedHandle;        /* 0xd4 */
    int  nSpeed;              /* 0xd8 */
} Ov023Anim;

typedef struct Ov023Entity {
    int  nFlags;              /* 0x00 */
    Ov023Anim anim;           /* 0x04 */
} Ov023Entity;

typedef struct Ov023Motion {
    int  nEndFrame;           /* 0x00 */
    s16  nFrame;              /* 0x04 */
    u8   pad_06[2];
    int  nBlend;              /* 0x08 */
    char szName[0x20];        /* 0x0c */
} Ov023Motion;                /* 0x2c */

typedef struct Ov023Actor {
    u8   pad_0000[0x538];
    Ov023Motion aMotion[5][5]; /* 0x0538: [depth][track] */
    u8   pad_0984[0x15e0 - 0x984];
    Ov023Entity *pEntity;     /* 0x15e0 */
    u8   pad_15e4[0x1a24 - 0x15e4];
    void *pMotionText;        /* 0x1a24 */
    int  nFlags;              /* 0x1a28 */
} Ov023Actor;

extern void  NNS_G3dRenderObjRemoveAnmObj(u32 *pAnimControl, int nHandle);        /* Anim_Unhook */
extern void  strcpy(char *pszDst, const char *pszSrc);       /* STD_CopyString */
extern int   strlen(const char *pszString);
extern int   strcmp(const char *pA, const char *pB);         /* STD_CompareString */
extern void *Msg_OpenContainerAndReadHeader(const char *pszName, int nHeap);         /* open a text container */
extern void  Ov023_ActorStartMotion(Ov023Actor *pActor, int nTrack);  /* Ov023_ActorStartMotion */
extern void  Ov023_ResetActorModel(Ov023Actor *pActor);               /* Ov023_ResetActorModel */
extern char  gOv023P2Name_2[];                                 /* ".p2" */

void Ov023_ActorPlayMotion(Ov023Actor *pActor, char *pszMotion, int nFrame, int nTrack, int nBlend)
{
    char szName[0x20];
    Ov023Anim *pAnim;
    int bAny;
    int i;
    Ov023Motion *pMotion;

    pAnim = &pActor->pEntity->anim;
    bAny = 0;
    if (pAnim->wFlags & 4) {
        if (pAnim->nHandle != 0) {
            NNS_G3dRenderObjRemoveAnmObj(&pAnim->nControl, pAnim->nHandle);
        }
        pAnim->wTrack = pAnim->nSavedTrack;
        pAnim->nSpeed = 0x1000;
        pAnim->nSavedTrack = -1;
        pAnim->nHandle = pAnim->nSavedHandle;
        pAnim->nSavedHandle = 0;
        pAnim->wFlags &= ~4;
    }
    if (pszMotion[0] != 0) {
        strcpy(szName, pszMotion);
        if (strcmp(szName + (strlen(szName) - 3), gOv023P2Name_2) == 0 && pActor->pMotionText == 0) {
            pActor->pMotionText = Msg_OpenContainerAndReadHeader(szName, 0xd);
        }
    } else {
        szName[0] = 0;
    }
    pMotion = &pActor->aMotion[0][nTrack];
    pMotion->nFrame = nFrame;
    pMotion->nBlend = nBlend;
    strcpy(pMotion->szName, szName);
    Ov023_ActorStartMotion(pActor, nTrack);
    for (i = 0; i < 5; i++) {
        pActor->aMotion[i][nTrack].nFrame = -1;
    }
    for (i = 0; i < 5; i++) {
        if (pActor->aMotion[0][i].nFrame != -1) {
            bAny = 1;
        }
    }
    if (!bAny) {
        pActor->nFlags &= ~0x200;
    }
    if ((pActor->nFlags & 0x80) && nTrack == 0) {
        Ov023_ResetActorModel(pActor);
    }
}
