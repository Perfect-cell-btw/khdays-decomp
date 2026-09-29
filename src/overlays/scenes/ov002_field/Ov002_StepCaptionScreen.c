/*
 * Ov002_StepCaptionScreen - the caption screen's per-frame step.
 *
 * The state word picks one of four handlers out of a table copied to the stack.
 * Once the screen reports it is settled, a sound is played from whichever table
 * the current line calls for, indexed by the player the other overlay names.
 * The progress bar is stepped last, and only while it is wanted.
 *
 * The scene slot is reached as an element of the caption screen's slot table
 * rather than through a cast onto the symbol's address. The two spell the same
 * word, but only the array form makes the compiler materialise the table base
 * ahead of the stack copy and displace it afterwards, which is what the original
 * does; an address plus a constant gets folded into a single pinned operand, and
 * a sized array folds the same way. The size has to stay unknown here.
 *
 * ARM.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct {
    void (*aStep[4])(void);
} Ov002StepTable;

typedef struct {
    char pad000[8];
    int nState;
    int nLine;
    char pad010[0x98];
    int nBar;
} Ov002CaptionScene;

extern Ov002CaptionScene *data_ov002_0207f62c[];
extern const Ov002StepTable data_ov002_0207e378;
extern const int data_ov002_0207e3c4[];
extern const int data_ov002_0207e368[];

extern int Ov105_WM_GetLinkLevel(void);

extern int Ov002_ForwardToSubDc(int nSound);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int);
extern void Ov002_StepProgressBar(void);

int Ov002_StepCaptionScreen(void)
{
    Ov002StepTable steps = data_ov002_0207e378;
    Ov002CaptionScene *s = data_ov002_0207f62c[1];
    const int *pTable;

    steps.aStep[s->nState]();

    if (Session_IsActive() != 0) {
        if (s->nLine == 0) {
            pTable = &data_ov002_0207e3c4[s->nLine * 4];
        } else {
            pTable = data_ov002_0207e368;
        }
        Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc((u16)pTable[Ov105_WM_GetLinkLevel()]));
    }

    if (s->nBar != 0) {
        Ov002_StepProgressBar();
    }
    return 0;
}
