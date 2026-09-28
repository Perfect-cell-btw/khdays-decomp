typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct Ov002PieceClass {
    char pad000[0x6c];
    int nReplayLimit;           /* +0x6c */
} Ov002PieceClass;

typedef struct Ov002PieceElement {
    char pad000[8];
    Ov002PieceClass *pOwner;    /* +0x08 */
    char pad00c[6];
    u16 wFlags;                 /* +0x12 */
    char pad014[0x28];
    short aAnimTracks[1];       /* +0x3c */
    char pad03e[0x172];
    int aClock[1];              /* +0x1b0 */
    s16 nDropScale;             /* +0x1b4 */
    u8 bDropsOn : 1;            /* +0x1b6 bit 0 */
    u8 nReplays : 7;            /* +0x1b6 bits 1..7 */
    u8 nAnimCounter;            /* +0x1b7 */
} Ov002PieceElement;

typedef void *Ov002StateFn(void *pElement);

extern int Ov002_GetModuleScale(void);           /* the module's time scale */
extern int Ov002_AdvanceElementClock(char *pElement, short *pTable, int nDelta,
                               int nFlag, int nLimit, int *pCounter);
extern void Ov002_SetFieldBit0(char *pElement, int nMode);
extern void Ov002_RebindAnimTracks(short *pAnim, int nTrack, int nFrame);
extern void SceneNode_Enable(short *pAnim);
extern void Scene_DrawNode(short *pAnim);

extern Ov002StateFn Ov002_DoneTick;

/* The recovery state a defeated piece sits in.  Each tick advances the piece's
   clock; while the animation is still running the piece just renders and stays
   here, and returning zero is what keeps it in this state.

   When the clock runs out the replay counter steps.  There are nReplays goes in
   all, packed into the top seven bits of the same byte whose bit 0 gates the
   payout; once they are spent the piece is put to sleep and the idle handler
   takes over.  Otherwise the next track is bound and played, and the piece
   comes back here for another go. */
Ov002StateFn *Ov002_TickPieceRecovery(Ov002PieceElement *pElement)
{
    Ov002PieceClass *pClass;
    int nScale;
    int bClockDone;
    u8 nCount;

    pClass = pElement->pOwner;
    nScale = Ov002_GetModuleScale();
    bClockDone = 0;
    if (Ov002_AdvanceElementClock((char *)pElement, pElement->aAnimTracks, nScale, 0,
                            pClass->nReplayLimit, pElement->aClock) == 0) {
        bClockDone = 1;
    }

    if ((pElement->wFlags & 4) != 0) {
        Scene_DrawNode(pElement->aAnimTracks);
    }

    if (bClockDone != 0) {
        nCount = ++pElement->nAnimCounter;
        if (nCount < pElement->nReplays) {
            if ((pElement->wFlags & 4) != 0) {
                Ov002_RebindAnimTracks(pElement->aAnimTracks, nCount, 0);
                SceneNode_Enable(pElement->aAnimTracks);
            }
        } else {
            Ov002_SetFieldBit0((char *)pElement, 0);
            return Ov002_DoneTick;
        }
    }
    return 0;
}
