/*
 * Ov002_PlayCaptionCues - play or stop the four cues that go with a caption.
 *
 * The bits the mixer hands back say which of the four cues are wanted. Each one
 * is looked up in a table - the shared one, or the row of the line being shown -
 * and panned a little further left than the cue before it.
 *
 * The same walk both starts and stops them, which is what the second argument
 * picks.
 *
 * ARM.
 */

#include "nitro/types.h"

typedef struct {
    char pad000[0xc];
    int nLine;
} Ov002CaptionScene;

extern int data_ov002_0207f62c;
extern const u16 data_ov002_0207e360[];
extern const u16 data_ov002_0207e388[];

extern int Ov002_GetPanelField01ae(void);
extern int Ov002_ForwardToSubDc(int nCue);
extern int Ov002_PositionSubDcHandle_2(int nHandle, int nPan, int nColour);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int nHandle);
extern void Ov002_ForwardToSubDc_2(int nHandle);

void Ov002_PlayCaptionCues(int bPerLine, int bStart)
{
    Ov002CaptionScene *s;
    const u16 *pCues;
    int i;
    int nPan;
    int nHandle;
    int nMask;

    s = *(Ov002CaptionScene **)((char *)&data_ov002_0207f62c + 4);
    nPan = 0x1e;
    nMask = Ov002_GetPanelField01ae();
    if (nMask == 0) {
        return;
    }

    if (bPerLine != 0) {
        pCues = &data_ov002_0207e388[s->nLine * 4];
    } else {
        pCues = data_ov002_0207e360;
    }

    for (i = 3; i >= 0; i--) {
        if ((nMask & (1 << i)) != 0) {
            nHandle = Ov002_ForwardToSubDc(pCues[i]);
            Ov002_PositionSubDcHandle_2(nHandle, (short)nPan, 0);
            if (bStart != 0) {
                Ov002_Ctx_InvokeTagTrackerCallback(nHandle);
            } else {
                Ov002_ForwardToSubDc_2(nHandle);
            }
            nPan -= 2;
        }
    }
}
