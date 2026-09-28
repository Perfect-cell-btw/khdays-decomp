/* Ov025_InitMissionListTrackers -- Ov008_InitMissionListTrackers: register the mission
 * list's three touch trackers in block 954c -- tag 0 (0x10, 0x30, 0xe0 x
 * 0x80, callback 02073e58), tag 1 (8, 8, 0x48 x 0x20, 02073f44) and tag 2
 * (0x10, 0x10, 0xe0 x 0xa0, 02073e58), all with mask 0xffff -- unless the
 * entry gate (+0x40) is set without the transfer ack (+0x44).  With context
 * object 9634 present tag 2 is disabled and tags 0 / 1 enabled, otherwise
 * tags 0 / 1 are disabled and tag 2 enabled.  Widgets 0x35 and 0x36 of block
 * 4a80 get callbacks 02073fe8 and 0207403c.
 */

#include "nitro/types.h"

#define TRACKER_MASK 0xffff
#define WIDGET_A 0x35
#define WIDGET_B 0x36

typedef void (*Ov008ItemCb)(void);

typedef struct Ov008MissionList {
    u8  pad_00[0x40];
    int bEntryGate;           /* 0x40 */
    int bTransferAcked;       /* 0x44 */
} Ov008MissionList;

extern void *Ov025_GetCtxBlock954c(void);                                   /* Ov008_GetCtxBlock954c */
extern void *Ov025_FindEntryByTag(void *pOwner, int nTag);                 /* ov008_FindEntryByTag */
extern void  Ov025_InitAndAppendTracker(void *pOwner, void *pEntry, int nX, int nY, int nW, int nH, int nMask, Ov008ItemCb pCallback); /* Ov008_InitAndAppendTracker */
extern int   Ov025_GetCtxObject9634(void);                                   /* Ov008_GetCtxObject9634 */
extern void  Ov025_SetField20Bit0(void *pOwner, void *pEntry, int bEnabled); /* SetField20Bit0 */
extern int   Ov025_GetBlock4a80(void);                                   /* Ov008_GetCtxBlock4a80 */
extern void  Ov025_ResolveEntryStoreWord(int nCtx, int nId, void *pCallback);     /* Ov008_ResolveEntryStoreWord */
extern void  Ov025_MissionListTouchRow(void);
extern void  Ov025_MissionListTouchConfirm(void);
extern void  Ov025_StepIfReadyAlt(void);
extern void  Ov025_ClosePopup(void);

void Ov025_InitMissionListTrackers(Ov008MissionList *pList)
{
    void *pOwner;
    int nCtx;

    pOwner = Ov025_GetCtxBlock954c();
    if (pList->bEntryGate != 0 && pList->bTransferAcked == 0) {
        return;
    }
    Ov025_InitAndAppendTracker(pOwner, Ov025_FindEntryByTag(pOwner, 0), 0x10, 0x30, 0xe0, 0x80, TRACKER_MASK, Ov025_MissionListTouchRow);
    Ov025_InitAndAppendTracker(pOwner, Ov025_FindEntryByTag(pOwner, 1), 8, 8, 0x48, 0x20, TRACKER_MASK, Ov025_MissionListTouchConfirm);
    Ov025_InitAndAppendTracker(pOwner, Ov025_FindEntryByTag(pOwner, 2), 0x10, 0x10, 0xe0, 0xa0, TRACKER_MASK, Ov025_MissionListTouchRow);
    if (Ov025_GetCtxObject9634() != 0) {
        Ov025_SetField20Bit0(pOwner, Ov025_FindEntryByTag(pOwner, 2), 0);
        Ov025_SetField20Bit0(pOwner, Ov025_FindEntryByTag(pOwner, 0), 1);
        Ov025_SetField20Bit0(pOwner, Ov025_FindEntryByTag(pOwner, 1), 1);
    } else {
        Ov025_SetField20Bit0(pOwner, Ov025_FindEntryByTag(pOwner, 0), 0);
        Ov025_SetField20Bit0(pOwner, Ov025_FindEntryByTag(pOwner, 1), 0);
        Ov025_SetField20Bit0(pOwner, Ov025_FindEntryByTag(pOwner, 2), 1);
    }
    nCtx = Ov025_GetBlock4a80();
    Ov025_ResolveEntryStoreWord(nCtx, WIDGET_A, Ov025_StepIfReadyAlt);
    Ov025_ResolveEntryStoreWord(nCtx, WIDGET_B, Ov025_ClosePopup);
}
