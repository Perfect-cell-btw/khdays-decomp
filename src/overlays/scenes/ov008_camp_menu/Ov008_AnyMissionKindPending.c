/* Ov008_AnyMissionKindPending -- Ov008_AnyMissionKindPending: walks the mission list
 * entries in order; returns 1 at the first entry whose kind (byte +0xd, 1-based)
 * has its two-bit game field (0x379f + 2 * (kind - 1)) at exactly 1 (unlocked but
 * not yet maxed), and 0 once the entries run out.
 */

#include "nitro/types.h"

typedef struct Ov008MissionListEntry {
    u8 pad_00[0xd];
    u8 nKind;                 /* 0x0d: 1-based, 0 = none */
} Ov008MissionListEntry;

#define FIELD_SLOT_BASE 0x379f
#define FIELD_SLOT_BITS 2

extern long long OS_GetTick(void);                                    /* GetTick64 */
extern Ov008MissionListEntry *Ov008_GetNextMissionEntry_2(int nIndex);
extern u32 GameState_GetField(int nField, int nBits);                         /* GameState_GetField */

/* nBase is a real (zero) page offset in the ROM: with propagation off it stays a
 * register, hoisted out of the loop as a copy of i's zero. */
static inline int Ov008_SlotFieldId(int nBase, int nKind)
{
    return FIELD_SLOT_BASE + ((u16)(nBase + (nKind - 1)) << 1);
}

static inline int Ov008_IsSlotUnlocked(int nField)
{
    return GameState_GetField(nField, FIELD_SLOT_BITS) >= 1;
}

static inline int Ov008_IsSlotMaxed(int nField)
{
    return GameState_GetField(nField, FIELD_SLOT_BITS) >= 2;
}

#pragma push
#pragma opt_propagation off
int Ov008_AnyMissionKindPending(void)
{
    Ov008MissionListEntry *pEntry;
    int nField;
    int i;

    i = 0;
    OS_GetTick();
    for (; ; i++) {
        pEntry = Ov008_GetNextMissionEntry_2(i);
        if (pEntry == 0) {
            break;
        }
        if (pEntry->nKind != 0) {
            int nBase = 0;
            nField = Ov008_SlotFieldId(nBase, pEntry->nKind);
            if (Ov008_IsSlotUnlocked(nField) && !Ov008_IsSlotMaxed(nField)) {
                return 1;
            }
        }
    }
    return 0;
}
#pragma pop
