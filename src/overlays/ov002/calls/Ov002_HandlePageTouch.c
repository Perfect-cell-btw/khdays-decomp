/*
 * Ov002_HandlePageTouch - hand a touch to whichever queued cue owns it.
 *
 * A touch that has not changed since last time is ignored. A press walks the
 * queued cues and gives the first one whose box holds the point its callback,
 * playing the cue itself only while this slot is the one on screen.
 *
 * A release stops whatever the slot was holding.
 *
 * ARM.
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef void (*Ov002CueProc)(int nHandle);

typedef struct {
    int hCue;
    int hAlt;
    short nGroup;
    u8 nX;
    u8 nY;
    u8 nWidth;
    u8 nHeight;
    char pad00e[2];
    Ov002CueProc pfn;
    char pad014[0xc];
} Ov002CueNode;

typedef struct {
    char pad000[8];
    char aList[0x20];
    int hHeld;
} Ov002CueCtx;

typedef struct {
    char pad000[0x10];
    u16 wButtons;
    char pad012[2];
} Ov002TabSlot;

typedef struct {
    u16 wX;
    u16 wY;
    u16 wButtons;
} Ov002TouchInput;

extern Ov002TabSlot data_ov002_0207f9a0[];
extern Ov002CueCtx *data_ov002_0207f99c;

extern void *NNS_FndGetNextListObject(void *pList, void *pObject);

extern int Session_GetLocalPlayerIndex(void);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int nHandle);

void Ov002_HandlePageTouch(int nSlot, const Ov002TouchInput *pInput)
{
    Ov002TabSlot *pSlot;
    Ov002CueCtx *ctx;
    Ov002CueNode *pNode;
    int nHandle;

    pSlot = &data_ov002_0207f9a0[nSlot];
    ctx = data_ov002_0207f99c;
    if ((pInput->wButtons ^ pSlot->wButtons) == 0) {
        return;
    }

    if (pInput->wButtons != 0) {
        pNode = (Ov002CueNode *)NNS_FndGetNextListObject(ctx->aList, 0);
        if (pNode == 0) {
            return;
        }
        do {
            if (pNode->nX <= pInput->wX &&
                pInput->wX <= pNode->nX + pNode->nWidth &&
                pNode->nY <= pInput->wY &&
                pInput->wY <= pNode->nY + pNode->nHeight &&
                pNode->pfn != 0) {
                if (nSlot == Session_GetLocalPlayerIndex()) {
                    if (pNode->hAlt != 0) {
                        Ov002_Ctx_InvokeTagTrackerCallback(pNode->hAlt);
                    }
                    nHandle = pNode->hCue;
                } else {
                    nHandle = 0;
                }
                pNode->pfn(nHandle);
                return;
            }
            pNode = (Ov002CueNode *)NNS_FndGetNextListObject(ctx->aList, pNode);
        } while (pNode != 0);
        return;
    }

    if (nSlot == Session_GetLocalPlayerIndex() && ctx->hHeld != 0) {
        Ov002_Ctx_InvokeTagTrackerCallback(ctx->hHeld);
        ctx->hHeld = 0;
    }
}
