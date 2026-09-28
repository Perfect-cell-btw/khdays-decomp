/* Draws one of the three mission-summary headings into the shared heading
 * surface. Multiplayer waits for the session-ready signal before touching the
 * surface; every accepted call brackets its draw with begin/submit. */

#include "nitro/types.h"

typedef struct Ov008MenuContext {
    u8 pad0000[0x1420];
    u8 headingSurface[0x3c];
    u8 pad145c[0x84];
    int multiplayerMode;
    u8 pad14e4[0x10];
    u8 textRecords[0x48];
} Ov008MenuContext;

extern Ov008MenuContext *Ov025_GetPageA(void);
extern int Session_IsReady(void);
extern void Obj_InvokeInnerVtable4(void *object);
extern void *Ov025_GetVarRecordByIndex(void *records, int index);
extern void Text_DrawDirectional_2(void *object, int x, int y, int enabled,
                          unsigned int flags, const void *text);
extern void EnqueueObjGfxCommand(void *object);
extern const u8 data_ov025_020b4d10[];

void Ov025_DrawMissionSummaryHeading(int headingMode)
{
    Ov008MenuContext *menuContext = Ov025_GetPageA();
    void *text;

    if (menuContext->multiplayerMode != 0 && Session_IsReady() == 0) {
        return;
    }

    Obj_InvokeInnerVtable4(menuContext->headingSurface);
    switch (headingMode) {
    case 0:
        Text_DrawDirectional_2(menuContext->headingSurface, 0x8e, 2, 1, 0x821,
                      data_ov025_020b4d10);
        break;
    case 1:
        text = Ov025_GetVarRecordByIndex(menuContext->textRecords, 2);
        Text_DrawDirectional_2(menuContext->headingSurface, 0x8e, 2, 1, 0x821, text);
        break;
    case 2:
        text = Ov025_GetVarRecordByIndex(menuContext->textRecords, 0);
        Text_DrawDirectional_2(menuContext->headingSurface, 0x8e, 2, 1, 0x821, text);
        break;
    }
    EnqueueObjGfxCommand(menuContext->headingSurface);
}
