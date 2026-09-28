/* Ov017_ItemStep -- Ov017_ItemStep: first state function of an item piece.  In state 0
 * it takes a spawn id from the low band (ov002 02077b30), queues a type-1 message (kind 6)
 * carrying it (ov002 020766e0) and moves to state 2; once the id has come back (+0x1b9 != -1,
 * set by the type-1 message handler) it moves to state 3 and hands over to the dispatching
 * state Ov017_ItemDispatchState (0208079c).  Otherwise stays (0). */

#include "nitro/types.h"

typedef struct Ov017ItemMessage {
    u8   nType;               /* 0x00: 1 */
    u8   pad_01[3];
    u8   nSpawnId;            /* 0x04 */
    u8   pad_05;
} Ov017ItemMessage;

typedef struct Ov017Item {
    u8   pad_000[0x1b4];
    u8   nState;              /* 0x1b4 */
    u8   pad_1b5[4];
    char nSpawnId;            /* 0x1b9: -1 until the message comes back */
} Ov017Item;

extern int   Ov002_TakeEntryOfKind1(void);                               /* take a spawn id from the low band */
extern int   Ov002_RecordElementHit(void *pPiece, void *pMessage, int nKind); /* queue a message on the piece */
extern void *Ov017_GetCallbackForState1b4(Ov017Item *pSelf);                   /* Ov017_ItemDispatchState */

void *Ov017_ItemStep(Ov017Item *pSelf)
{
    Ov017ItemMessage message;

    if (pSelf->nState == 0) {
        message.nType = 1;
        message.nSpawnId = Ov002_TakeEntryOfKind1();
        Ov002_RecordElementHit(pSelf, &message, 6);
        pSelf->nState = 2;
    } else if (pSelf->nSpawnId != -1) {
        pSelf->nState = 3;
        return Ov017_GetCallbackForState1b4;
    }
    return 0;
}
