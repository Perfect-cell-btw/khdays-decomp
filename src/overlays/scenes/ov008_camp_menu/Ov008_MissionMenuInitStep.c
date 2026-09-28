/* Ov008_MissionMenuInitStep -- Ov008_MissionMenuInitStep: one step of the mission
 * menu's start-up (+0x0), returning 1 once done.  Step 0 clears the two
 * selection words (+0x180 / +0x184), sets the transfer flag (+0x150) when
 * context object 95c0 is 2 -- then the transfer ack (+0x154) is "no session
 * or session ready" and handler 02077b0c is stored at gate 0 -- takes the
 * cursor slot (+0x56c) from the smallest list value when transferring,
 * acquires message dbs 0x15 / 0x19 / 0x1a, loads the flag table (+0x174),
 * points the two text loaders (+0x530, +0x53c) at the mission / status
 * strings, opens the mission list (+0x548) with descriptor 0208fa1c when
 * context object 9634 exists (0208fa10 otherwise), refreshes the entries,
 * loads the graphics, creates the surfaces, allocates the scroll code node
 * (+0x170, running 02074560) and parks the page scroll (+0x168) at -0x40.
 * Step 1 hides the widgets, registers the trackers, redraws the rows and
 * page panel, on more than one selectable mission (+0x17a) sets tags 0xc / 0xd
 * of block 954c, switches to tab 1 when object 9634 exists without a
 * transfer (else 0) and marks slots 0x1a / 0x1b used.  Step 2 draws heading
 * 2.
 * Codegen: the widget hide (02077554) and the graphics load (02077190) are
 * called WITH the menu pointer although neither reads it -- case 1's opening
 * call then reuses the incoming r0 (no `mov r0, r5`), and that keeps r0 live
 * through the switch chain so the step temporary takes r1 as the ROM does.
 */
#include "nitro/types.h"

#define SCROLL_HIDDEN (-0x40)

typedef struct Ov008MissionResourceDescriptor {
    const u8 *resourcePath;
    int selector;
    int listKind;
} Ov008MissionResourceDescriptor;

typedef struct Ov008MissionMenu {
    int nInitStep;            /* 0x000 */
    u8  pad_004[0x150 - 0x4];
    int bTransfer;            /* 0x150 */
    int bTransferAcked;       /* 0x154 */
    u8  pad_158[0x168 - 0x158];
    int nPageScroll;          /* 0x168 */
    u8  pad_16c[4];
    void *pListNode;          /* 0x170 */
    void *pFlagTable;         /* 0x174 */
    u8  nCount;               /* 0x178 */
    u8  nCursor;              /* 0x179 */
    u8  nSelectable;          /* 0x17a */
    u8  pad_17b[0x180 - 0x17b];
    int bSelectionPending;    /* 0x180 */
    int bSelectionArmed;      /* 0x184 */
    u8  pad_188[0x530 - 0x188];
    u8  textCacheA[0xc];      /* 0x530 */
    u8  textCacheB[0xc];      /* 0x53c */
    u8  missionList[0x24];    /* 0x548 */
    u8  nCursorSlot;          /* 0x56c */
} Ov008MissionMenu;

extern const char data_ov008_020909a4[];                                  /* "UI/cm/str/mission_&.s.z" */
extern const char data_ov008_020909bc[];                                  /* "UI/cm/str/status_&.s.z" */
extern const Ov008MissionResourceDescriptor data_ov008_0208fa1c;
extern const Ov008MissionResourceDescriptor data_ov008_0208fa10;
extern int  Ov008_GetCtxObject95c0(void);                                    /* Ov008_GetCtxObject95c0 */
extern int  Session_IsActive(void);                                          /* Session_IsActive */
extern int  Session_IsReady(void);                                          /* Session_IsReady */
extern void StoreGlobalPtrArray4At0c(int nGate, void *pHandler);                     /* StoreGlobalPtrArray4At0c */
extern void Ov008_MissionMenu_OnConfirm(void);                                    /* gate 0 handler */
extern u32  Ov008_FindMinListValue_3(void);                                    /* FindMinListValue */
extern int  Ov008_AcquireMsgDb(int nDb);                                 /* Ov008_AcquireMsgDb */
extern void Ov008_RelocateOffsetTable2(Ov008MissionMenu *pMenu);                 /* load the flag table */
extern void Ov008_VarTable_Load(void *pLoader, const char *pPath);        /* Ov008_Set_5c4c */
extern int  Ov008_GetCtxObject9634(void);                                    /* Ov008_GetCtxObject9634 */
extern void Ov008_InitMissionList(void *pList, Ov008MissionResourceDescriptor *pDescriptor); /* Ov008_InitMissionList */
extern void Ov008_MissionMenuRefreshEntries(Ov008MissionMenu *pMenu);                 /* Ov008_MissionMenuRefreshEntries */
extern void Ov008_LoadMissionMenuGraphics(Ov008MissionMenu *pMenu);                 /* Ov008_LoadMissionMenuGraphics (pMenu unused) */
extern void Ov008_InitMissionMenuSurfaces(Ov008MissionMenu *pMenu);                 /* Ov008_InitMissionMenuSurfaces */
extern void *Ov008_AllocCodeNode(void *pFn);                              /* Ov008_AllocCodeNode */
extern void Ov008_UpdateBg3ScrollFromPage(void);                                    /* Ov008_UpdateBg3ScrollFromPage */
extern void  Ov008_HideMissionMenuWidgets(Ov008MissionMenu *pMenu);                 /* Ov008_HideMissionMenuWidgets (pMenu unused) */                                    /* Ov008_HideMissionMenuWidgets */
extern void Ov008_InitMissionMenuTrackers(Ov008MissionMenu *pMenu);                 /* Ov008_InitMissionMenuTrackers */
extern void Ov008_LayoutMissionBadges(Ov008MissionMenu *pMenu);                 /* redraw rows */
extern void Ov008_DrawMissionDetail(Ov008MissionMenu *pMenu, int nPage);      /* redraw page panel */
extern int  Ov008_GetCtxBlock954c(void);                                    /* Ov008_GetCtxBlock954c */
extern void Ov008_SetActiveTagValueAndFlag(int nCtx, u32 nTag, u16 nValue, u16 nFlag); /* Ov008_SetActiveTagValueAndFlag */
extern void Ov008_SwitchMenuTab(Ov008MissionMenu *pMenu, int nTab);       /* Ov008_SwitchMenuTab */
extern void Ov008_MarkSlotUsed(int nSlot);                               /* Ov008_MarkSlotUsed */
extern void Ov008_DrawMissionSummaryHeading(int nHeadingMode);                        /* Ov008_DrawMissionSummaryHeading */

int Ov008_MissionMenuInitStep(Ov008MissionMenu *pMenu)
{
    int bDone;
    Ov008MissionResourceDescriptor descriptorA;
    Ov008MissionResourceDescriptor descriptorB;
    int bReady;
    int nCtx;
    int nTab;

    bDone = 0;
    switch (pMenu->nInitStep) {
    case 0:
        pMenu->bSelectionPending = 0;
        pMenu->bSelectionArmed = 0;
        pMenu->bTransfer = Ov008_GetCtxObject95c0() == 2;
        if (pMenu->bTransfer) {
            if (Session_IsActive() == 0 || Session_IsReady() != 0) {
                bReady = 1;
            } else {
                bReady = 0;
            }
            pMenu->bTransferAcked = bReady;
            StoreGlobalPtrArray4At0c(0, Ov008_MissionMenu_OnConfirm);
        }
        if (pMenu->bTransfer != 0) {
            pMenu->nCursorSlot = Ov008_FindMinListValue_3();
        }
        Ov008_AcquireMsgDb(0x15);
        Ov008_AcquireMsgDb(0x19);
        Ov008_AcquireMsgDb(0x1a);
        pMenu->pFlagTable = 0;
        Ov008_RelocateOffsetTable2(pMenu);
        Ov008_VarTable_Load(pMenu->textCacheA, data_ov008_020909a4);
        Ov008_VarTable_Load(pMenu->textCacheB, data_ov008_020909bc);
        if (Ov008_GetCtxObject9634() != 0) {
            descriptorA = data_ov008_0208fa1c;
            Ov008_InitMissionList(pMenu->missionList, &descriptorA);
        } else {
            descriptorB = data_ov008_0208fa10;
            Ov008_InitMissionList(pMenu->missionList, &descriptorB);
        }
        Ov008_MissionMenuRefreshEntries(pMenu);
        Ov008_LoadMissionMenuGraphics(pMenu);
        Ov008_InitMissionMenuSurfaces(pMenu);
        pMenu->pListNode = Ov008_AllocCodeNode(Ov008_UpdateBg3ScrollFromPage);
        pMenu->nPageScroll = SCROLL_HIDDEN;
        pMenu->nInitStep++;
        break;
    case 1:
        Ov008_HideMissionMenuWidgets(pMenu);
        Ov008_InitMissionMenuTrackers(pMenu);
        Ov008_LayoutMissionBadges(pMenu);
        Ov008_DrawMissionDetail(pMenu, 0);
        if (pMenu->nSelectable > 1) {
            nCtx = Ov008_GetCtxBlock954c();
            Ov008_SetActiveTagValueAndFlag(nCtx, 0xc, 0, 0);
            Ov008_SetActiveTagValueAndFlag(nCtx, 0xd, 0x1e, 0);
        }
        nTab = 0;
        if (Ov008_GetCtxObject9634() != 0) {
            nTab = pMenu->bTransfer == 0;
        }
        Ov008_SwitchMenuTab(pMenu, nTab);
        Ov008_MarkSlotUsed(0x1a);
        Ov008_MarkSlotUsed(0x1b);
        pMenu->nInitStep++;
        break;
    case 2:
        Ov008_DrawMissionSummaryHeading(2);
        bDone = 1;
        break;
    }
    return bDone;
}
