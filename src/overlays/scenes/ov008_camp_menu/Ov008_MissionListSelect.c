/* Ov008_MissionListSelect -- Ov008_MissionListSelect: start the selected mission.
 * Nothing with no selection.  The pick is refused (cue 4) when: without a modal
 * object the mission's status field (0x28e4 + 3 * id) is already 2 or more;
 * with one, during a page transition, either the list's entry gate (+0x40) is
 * set and the entry's rank (+8) exceeds the list's cap byte (+0x57), or the
 * gate is clear and the helper 0206fb2c answers 0.  Otherwise the mission id is
 * stored in the context, the selected row and the scroll (+0xc) are saved to
 * the 8-bit fields 0x35cd / 0x35df, global config 2 is initialised and cue 1
 * plays.
 */
#include "nitro/types.h"

#define FIELD_MISSION_STATUS 0x28e4
#define FIELD_SCROLL_A       0x35cd
#define FIELD_SCROLL_B       0x35df

typedef struct Ov008MissionListEntry {
    u8  pad_00[2];
    u16 missionId;            /* 0x02 */
} Ov008MissionListEntry;

typedef struct Ov008MissionList {
    int nSelected;            /* 0x000 */
    u8  pad_004[8];
    int nScroll;              /* 0x00c */
    u8  pad_010[0x40 - 0x10];
    int bEntryGate;           /* 0x040 */
} Ov008MissionList;

extern Ov008MissionListEntry *Ov008_GetNextMissionEntry_2(int nIndex);
extern int  Ov008_GetCtxObject9630(void);                                    /* Ov008_GetCtxObject9630 */
extern u32  GameState_GetField(int nField, int nBits);                         /* GameState_GetField */
extern int  Ov008_GetCtxObject9634(void);                                    /* page transition active */
extern int  Ov008_IsField8LeField57(Ov008MissionList *pList, Ov008MissionListEntry *pEntry); /* IsField8LeField57 */
extern int  Ov008_DefaultStepDone(Ov008MissionList *pList, Ov008MissionListEntry *pEntry); /* ov008_helper_6fb2c (ignores its arguments) */
extern void Ov008_SetCtxField967c(u32 nMissionId);                          /* Ov008_SetCtxField967c */
extern void GameState_SetField(int nField, int nBits, int nValue);             /* GameState_SetField */
extern void Ov008_SetGlobalConfigAndInit(int nEntry);                              /* Ov008_SetGlobalConfigAndInit */
extern void PlaySound(int nKind, int nSound);                         /* PlaySound */

void Ov008_MissionListSelect(Ov008MissionList *pList)
{
    Ov008MissionListEntry *pEntry;
    int bRefused;

    if (pList->nSelected < 0) {
        return;
    }
    bRefused = 0;
    pEntry = Ov008_GetNextMissionEntry_2(pList->nSelected);
    if (Ov008_GetCtxObject9630() == 0) {
        if (GameState_GetField(pEntry->missionId * 3 + FIELD_MISSION_STATUS, 3) >= 2) {
            bRefused = 1;
        }
    } else if (Ov008_GetCtxObject9634() != 0) {
        if (pList->bEntryGate != 0) {
            if (Ov008_IsField8LeField57(pList, pEntry) == 0) {
                bRefused = 1;
            }
        } else {
            if (Ov008_DefaultStepDone(pList, pEntry) == 0) {
                bRefused = 1;
            }
        }
    }
    if (bRefused == 0) {
        Ov008_SetCtxField967c(Ov008_GetNextMissionEntry_2(pList->nSelected)->missionId);
        GameState_SetField(FIELD_SCROLL_A, 8, (u16)pList->nSelected);
        GameState_SetField(FIELD_SCROLL_B, 8, (u16)pList->nScroll);
        Ov008_SetGlobalConfigAndInit(2);
        PlaySound(0, 1);
    } else {
        PlaySound(0, 4);
    }
}
