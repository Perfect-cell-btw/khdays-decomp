/* Ov025_Hub_SetSubMenu -- show or hide the hub's sub-menu, ov025. Stores the state at +0x5c0, sets
 * the visibility of entries 7 and 8 and pushes the state to the sub-item sets of entries 1..6.
 * Showing: the tag-2 marker's callback runs, entries 0x10..0x12, 0xe and 0xf are hidden, the
 * sub-menu caption (text record 0x15) is drawn at (10, 0), entry 0x15's first valid slot is saved
 * to +0x5c4, entry 8 takes the parameter overrides and the hover (0x80) and becomes current
 * (+0x88, the hovered id), and entry 9's sub-items follow the state. Hiding: the hub entries are re-initialised,
 * entry 9's sub-items and the 0208acd8 refresh follow, entries 0x10..0x12, 0xe and 0xf are shown
 * again, entry 0x15 gets its saved slots back and entry 9 takes the overrides, the hover and the
 * focus. */
#include "nitro/types.h"

typedef struct Ov025HubScene {
    int nField00;                       /* +0x000 */
    u8 strings[0xc];                    /* +0x004: the hub string set */
    u8 surfaceTitle[0x3c];              /* +0x010 */
    u8 surfaceBody[0x3c];               /* +0x04c */
    int nHoverId;                       /* +0x088: the hovered entry id */
    u8 pad08c[0x5c0 - 0x8c];
    int bSubMenu;                       /* +0x5c0 */
    u8 savedSlots[8];                   /* +0x5c4: entry 0x15's slots while the sub-menu is open */
} Ov025HubScene;

extern int Ov025_GetCtxBlock9500(void);                                   /* tag tracker */
extern int Ov025_GetContext(void);                                   /* entry context */
extern void *Ov025_FindEntryById(int nCtx, int nId);                    /* FindEntryById */
extern void Ov025_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);  /* SetEntrySlotsVisible */
extern void Ov025_PushSubitemSet(int nCtx, void *pEntry, int nValue);    /* PushSubitemSet */
extern void *Ov025_FindEntryByTag(int nTracker, int nTag);               /* FindEntryByTag */
extern void Ov025_TagTracker_InvokeCallback(int nTracker, void *pCell);             /* invoke the tag callback */
extern void *Ov025_GetVarRecordByIndex(void *pRecords, int nIndex);           /* GetVarRecordByIndex */
extern void Obj_InvokeInnerVtable4(void *pSurface);                              /* TileSurface_Clear */
extern void Text_DrawWithShadow(void *pSurface, int nX, int nY, int nColour, void *pText, int nFlag);
extern void EnqueueObjGfxCommand(void *pSurface);
extern void *Ov025_ApplyFirstValidSlot(int nCtx, void *pEntry);               /* first valid slot */
extern void MI_CpuCopy8(const void *pSrc, void *pDst, unsigned int nSize);
extern void Ov025_SwapParamOverrides(int nCtx, void *pEntry);                /* swap parameter overrides */
extern void Ov025_Hub_OnEntryHover(void *pEntry, int nFlags);              /* hover */
extern void Ov025_Hub_InitEntries(Ov025HubScene *pScene);                 /* init the hub entries */
extern void Ov025_PushCountersToEventFlags(void);
extern void Ov025_ReleaseTwoSlotsEx(int nCtx, void *pEntry, void *pSlots);  /* release two slots */

void Ov025_Hub_SetSubMenu(Ov025HubScene *pScene, int bShow)
{
    int nTracker = Ov025_GetCtxBlock9500();
    int nCtx = Ov025_GetContext();

    pScene->bSubMenu = bShow;
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 7), bShow);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 8), bShow);
    Ov025_PushSubitemSet(nCtx, Ov025_FindEntryById(nCtx, 1), bShow);
    Ov025_PushSubitemSet(nCtx, Ov025_FindEntryById(nCtx, 2), bShow);
    Ov025_PushSubitemSet(nCtx, Ov025_FindEntryById(nCtx, 3), bShow);
    Ov025_PushSubitemSet(nCtx, Ov025_FindEntryById(nCtx, 4), bShow);
    Ov025_PushSubitemSet(nCtx, Ov025_FindEntryById(nCtx, 5), bShow);
    Ov025_PushSubitemSet(nCtx, Ov025_FindEntryById(nCtx, 6), bShow);
    if (bShow) {
        void *pText;

        Ov025_TagTracker_InvokeCallback(nTracker, Ov025_FindEntryByTag(nTracker, 2));
        Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x10), 0);
        Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x11), 0);
        Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x12), 0);
        Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0xe), 0);
        Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0xf), 0);
        pText = Ov025_GetVarRecordByIndex(pScene->strings, 0x15);
        Obj_InvokeInnerVtable4(pScene->surfaceBody);
        Text_DrawWithShadow(pScene->surfaceBody, 10, 0, 2, pText, 1);
        EnqueueObjGfxCommand(pScene->surfaceBody);
        MI_CpuCopy8(Ov025_ApplyFirstValidSlot(nCtx, Ov025_FindEntryById(nCtx, 0x15)), pScene->savedSlots, 8);
        Ov025_SwapParamOverrides(nCtx, Ov025_FindEntryById(nCtx, 8));
        pScene->nHoverId = 8;
        Ov025_Hub_OnEntryHover(Ov025_FindEntryById(nCtx, 8), 0x80);
        Ov025_PushSubitemSet(nCtx, Ov025_FindEntryById(nCtx, 9), bShow);
        return;
    }
    Ov025_Hub_InitEntries(pScene);
    Ov025_PushSubitemSet(nCtx, Ov025_FindEntryById(nCtx, 9), bShow);
    Ov025_PushCountersToEventFlags();
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x10), 1);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x11), 1);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x12), 1);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0xe), 1);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0xf), 1);
    Ov025_ReleaseTwoSlotsEx(nCtx, Ov025_FindEntryById(nCtx, 0x15), pScene->savedSlots);
    Ov025_SwapParamOverrides(nCtx, Ov025_FindEntryById(nCtx, 9));
    pScene->nHoverId = 9;
    Ov025_Hub_OnEntryHover(Ov025_FindEntryById(nCtx, 9), 0x80);
}
