/* Ov008_InitMissionMenuTrackers -- Ov008_InitMissionMenuTrackers: register the mission
 * menu's four touch trackers in block 954c -- tag 6 (0xe0, 0x40, 0x10 x
 * 0x60, callback 02078160), tag 0xf0 (8, 0x28, 0x50 x 0x10, 02078184), tag
 * 0xf1 (0x58, 0x28, 0x50 x 0x10, 020781b4) and tag 0xf2 (0xa8, 0x28, 0x50 x
 * 0x10, 020781e4), all with mask 0xffff -- unless the transfer flag (+0x150)
 * is set without its ack (+0x154); all four start disabled.  Widgets 0x35
 * and 0x36 of block 4a80 get callbacks 02078214 and 0207825c.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define TRACKER_MASK 0xffff
#define WIDGET_A 0x35
#define WIDGET_B 0x36

typedef void (*Ov008ItemCb)(void);

typedef struct Ov008MissionMenu {
    u8  pad_000[0x150];
    int bTransfer;            /* 0x150 */
    int bTransferAcked;       /* 0x154 */
} Ov008MissionMenu;

extern void *Ov008_GetCtxBlock954c(void);                                   /* Ov008_GetCtxBlock954c */
extern void *Ov008_FindEntryByTag(void *pOwner, int nTag);                 /* ov008_FindEntryByTag */
extern void  Ov008_InitAndAppendTracker(void *pOwner, void *pEntry, int nX, int nY, int nW, int nH, int nMask, Ov008ItemCb pCallback); /* Ov008_InitAndAppendTracker */
extern void  Ov008_SetField20Bit0(void *pOwner, void *pEntry, int bEnabled); /* SetField20Bit0 */
extern int   Ov008_GetCtxBlock4a80(void);                                   /* Ov008_GetCtxBlock4a80 */
extern void  Ov008_ResolveEntryStoreWord(int nCtx, int nId, void *pCallback);     /* Ov008_ResolveEntryStoreWord */
extern void  Ov008_BeginInfoPanelDrag(void);
extern void  Ov008_MissionMenu_SelectTab0(void);
extern void  Ov008_MissionMenu_SelectTab1(void);
extern void  Ov008_MissionMenu_SelectTab2(void);
extern void  Ov008_MissionConfirmGuard(void);
extern void  Ov008_MissionMenu_OnBack(void);

void Ov008_InitMissionMenuTrackers(Ov008MissionMenu *pMenu)
{
    void *pOwner;
    int nCtx;

    pOwner = Ov008_GetCtxBlock954c();
    if (pMenu->bTransfer != 0 && pMenu->bTransferAcked == 0) {
        return;
    }
    Ov008_InitAndAppendTracker(pOwner, Ov008_FindEntryByTag(pOwner, 6), 0xe0, 0x40, 0x10, 0x60, TRACKER_MASK, Ov008_BeginInfoPanelDrag);
    Ov008_InitAndAppendTracker(pOwner, Ov008_FindEntryByTag(pOwner, 0xf0), 8, 0x28, 0x50, 0x10, TRACKER_MASK, Ov008_MissionMenu_SelectTab0);
    Ov008_InitAndAppendTracker(pOwner, Ov008_FindEntryByTag(pOwner, 0xf1), 0x58, 0x28, 0x50, 0x10, TRACKER_MASK, Ov008_MissionMenu_SelectTab1);
    Ov008_InitAndAppendTracker(pOwner, Ov008_FindEntryByTag(pOwner, 0xf2), 0xa8, 0x28, 0x50, 0x10, TRACKER_MASK, Ov008_MissionMenu_SelectTab2);
    Ov008_SetField20Bit0(pOwner, Ov008_FindEntryByTag(pOwner, 6), 0);
    Ov008_SetField20Bit0(pOwner, Ov008_FindEntryByTag(pOwner, 0xf0), 0);
    Ov008_SetField20Bit0(pOwner, Ov008_FindEntryByTag(pOwner, 0xf1), 0);
    Ov008_SetField20Bit0(pOwner, Ov008_FindEntryByTag(pOwner, 0xf2), 0);
    nCtx = Ov008_GetCtxBlock4a80();
    Ov008_ResolveEntryStoreWord(nCtx, WIDGET_A, Ov008_MissionConfirmGuard);
    Ov008_ResolveEntryStoreWord(nCtx, WIDGET_B, Ov008_MissionMenu_OnBack);
}
