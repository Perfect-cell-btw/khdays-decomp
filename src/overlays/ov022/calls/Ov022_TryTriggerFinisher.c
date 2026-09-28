/* Ov022_TryTriggerFinisher -- decide whether this hit opens the finisher.
 *
 * Nothing opens unless the actor's follow block says so, the caller's flags do
 * not veto it, the actor's kind is allowed one at all and the finisher itself is
 * currently available. Past that it is a roll: an actor carrying the marked flag
 * rolls against the chance its own player table entry holds, and every other
 * actor against a flat fifty.
 *
 * Only the local player records the result: its window is pushed out and the
 * finisher bit goes into the sixty-four bit flag word.
 */

typedef unsigned char u8;

/* Ov022Actor */
struct Actor {
    unsigned int nFlags;             /* 0x0000 */
    u8 pad0004[5];
    u8 nId;                          /* 0x0009 */
    u8 pad000a[0x462];
    long long nFlags3;               /* 0x046c */
    u8 pad0474[0x40];
    int nInterruptCharge;            /* 0x04b4 */
    u8 pad04b8[0xcd4];
    u8 follow[4];                    /* 0x118c */
};

struct PlayerChance {
    u8 pad00[0x14];
    int nChance;                     /* 0x14 */
};

struct PlayerEntry {
    u8 pad00[0x44];
    struct PlayerChance *pChance;    /* 0x44 */
};

extern int Ov022_IsBit0Set_2(u8 *pBlock);
extern unsigned int Slot_EvalPackedParam(int nId, int nKey);
extern int Ov022_CanTriggerFinisher(struct Actor *pActor);
extern struct PlayerEntry *GetPlayerSlotTableEntry(int nSlot);
extern int Session_RandNext(void);
extern int Session_GetLocalPlayerIndex(void);

#define ACTOR_MARKED 0x10000
#define CALLER_VETO 0x80
#define PARAM_FINISHER 0x14
#define FINISHER_BIT 0x4000
#define WINDOW_PUSH 0x3000
#define ROLL_SCALE 0x64000
#define FLAT_CHANCE 0x32000

int Ov022_TryTriggerFinisher(struct Actor *pActor, unsigned int *pFlags)
{
    int bReady;
    struct PlayerEntry *pEntry;

    bReady = 0;
    if (Ov022_IsBit0Set_2(pActor->follow) == 0) {
        return 0;
    }
    if ((*pFlags & CALLER_VETO) != 0) {
        return 0;
    }
    if (Slot_EvalPackedParam(pActor->nId, PARAM_FINISHER) != 0) {
        bReady = Ov022_CanTriggerFinisher(pActor);
    }
    if (bReady != 0) {
        if ((pActor->nFlags & ACTOR_MARKED) != 0) {
            pEntry = GetPlayerSlotTableEntry((u8)(pActor->nId - 1));
            if (pEntry != 0 && pEntry->pChance != 0) {
                if ((int)(((long long)Session_RandNext() * ROLL_SCALE + 0x800)
                          >> 12) > pEntry->pChance->nChance) {
                    return 0;
                }
            }
        } else {
            if ((int)(((long long)Session_RandNext() * ROLL_SCALE + 0x800) >> 12)
                > FLAT_CHANCE) {
                return 0;
            }
        }
        if (Session_GetLocalPlayerIndex() == 0) {
            pActor->nInterruptCharge = pActor->nInterruptCharge + WINDOW_PUSH;
            pActor->nFlags3 |= FINISHER_BIT;
        }
        return 1;
    }
    return 0;
}
