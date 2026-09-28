/*
 * Ov002_DrawNoticeGauge - draw the notice bar and its beads.
 *
 * Nothing happens until a notice is up. The bar is redrawn from the entry that
 * owns it, and outside the one language that hides them, a bead is stamped every
 * two units across: the filled cue up to the count that is reached, then the
 * empty cue for the rest of the row.
 *
 * ARM.
 */

typedef struct {
    char pad000[0x94];
    int nNotice;
    char pad098[0xa0];
    char statusCtx[0x3c];
    char pad174[0x4c];
    int nFilled;
    int nTotal;
} Ov002CaptionScene;

extern int data_ov002_0207f62c;

extern int GameState_GetField(int nField, int nKind);
extern void EnqueueObjGfxCommand(void *pCtx);
extern void Draw_ScaledValue(void *pCtx, int nScreenBase, int a, int b, int c);

extern int Ov002_ForwardToSubDc(int nCue);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int nHandle);
extern int Ov002_PositionSubDcHandle_3(int nHandle, int nPos, int nMode);
extern int Ov002_GetItemResource(int nId);
extern void Ov002_SelectEntry(int nId);

void Ov002_DrawNoticeGauge(void)
{
    int i;
    int nCueFilled;
    int nCueEmpty;
    int nPos;
    Ov002CaptionScene *s;

    s = *(Ov002CaptionScene **)((char *)&data_ov002_0207f62c + 4);
    if (s->nNotice == 0) {
        return;
    }

    Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x41a));
    EnqueueObjGfxCommand(s->statusCtx);
    Draw_ScaledValue(s->statusCtx, Ov002_GetItemResource(0x1a), 0x16, 0xf, 0xc);

    if (GameState_GetField(0, 9) != 0x165) {
        nCueFilled = Ov002_ForwardToSubDc(0x400);
        nCueEmpty = Ov002_ForwardToSubDc(0x401);
        i = 0;
        if (i < s->nFilled) {
            nPos = 2;
            do {
                Ov002_PositionSubDcHandle_3(nCueFilled, (short)nPos, 0x16);
                nPos += 2;
                i++;
            } while (i < s->nFilled);
        }
        if (i < s->nTotal) {
            nPos = i * 2 + 2;
            do {
                Ov002_PositionSubDcHandle_3(nCueEmpty, (short)nPos, 0x16);
                nPos += 2;
                i++;
            } while (i < s->nTotal);
        }
    }
    Ov002_SelectEntry(0x1a);
}
