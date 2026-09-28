/* Ov025_TickMenuState -- Ov008_TickMenuState (268 B, 20 relocs).
 * Per-frame step of a menu sub-state machine, dispatched on p->state (0..6) and advanced by one
 * each call. Returns 1 only from the terminal step (state 6), 0 otherwise.
 *   0: first-time setup -- init the object list at p+0x1cc, clear the tween at p+0x1c, mark
 *      p->field0c, ref up message DBs 0x15/0x13/0x1c and the dynamic one from Ov025_GetMenuMsgDbId,
 *      build the menu screen, then Ov025_ScrollMenu_SetupEntries(p);
 *   1: raise the ready flag (data_ov025_020b575c = 1) and run the open animation;
 *   2/3: intermediate transition steps;
 *   6: allocate the code node (stored at p+0x23c), apply control value 1, and return 1.
 * Several helpers here (e.g. Ov025_AcquireMsgDb, Ov025_DrawStatusPage) are invoked with only the
 * arguments this state actually sets; the trailing register args they also read are left as the
 * caller's residue, matching the ROM. */
#include "nitro/types.h"

typedef struct Ov008State {
    u8  pad_0000[0x18];
    int state;          /* 0x18: dispatcher step (0..6) */
} Ov008State;

extern int   data_ov025_020b575c;
extern void  Ov025_SetupSubBgLayers(void);
extern void  NNS_FndInitList(void *list, int size);
extern void  Tween_Clear(void *tween);
extern int   Ov025_AcquireMsgDb(int id);
extern int   Ov025_GetMenuMsgDbId(void);
extern void  Ov025_BuildMenuScreen(int screen);
extern void  Ov025_ScrollMenu_SetupEntries(Ov008State *p);
extern void  Ov025_InitStatusPanelSurfaces(Ov008State *p, int *flag, int a3, int a4);
extern void  Ov025_DrawStatusPage(Ov008State *p);
extern void  Ov025_TickMenuStateHookNoOp(void);
extern void  Ov025_ResetScrollGauge(Ov008State *p);
extern void  Ov025_ChangeMenuSelection(Ov008State *p, int newSel, int a3);
extern void  Ov025_ScrollMenuMoveTo(Ov008State *p, int a, int b, int c);
extern int   Ov025_AllocAndRegisterEntry(void *fn);
extern void  Ov025_ApplyControlValue(int v);
extern void  Ov025_TickPageBTransition(void);

int Ov025_TickMenuState(Ov008State *p, int a2, int a3, int a4)
{
    int result = 0;

    switch (p->state) {
    case 0:
        Ov025_SetupSubBgLayers();
        NNS_FndInitList((char *)p + 0x1cc, 0x24);
        Tween_Clear((char *)p + 0x1c);
        *(int *)((char *)p + 0xc) = 1;
        Ov025_AcquireMsgDb(0x15);
        Ov025_AcquireMsgDb(0x13);
        Ov025_AcquireMsgDb(0x1c);
        Ov025_BuildMenuScreen(Ov025_AcquireMsgDb(Ov025_GetMenuMsgDbId()));
        Ov025_ScrollMenu_SetupEntries(p);
        break;
    case 1:
        data_ov025_020b575c = 1;
        Ov025_InitStatusPanelSurfaces(p, &data_ov025_020b575c, 1, a4);
        Ov025_DrawStatusPage(p);
        break;
    case 2:
        Ov025_TickMenuStateHookNoOp();
        Ov025_ResetScrollGauge(p);
        break;
    case 3:
        Ov025_ChangeMenuSelection(p, 1, 0);
        Ov025_ScrollMenuMoveTo(p, 0, 0, 1);
        break;
    case 6:
        *(int *)((char *)p + 0x23c) = Ov025_AllocAndRegisterEntry(Ov025_TickPageBTransition);
        Ov025_ApplyControlValue(1);
        result = 1;
        break;
    }
    p->state += 1;
    return result;
}
