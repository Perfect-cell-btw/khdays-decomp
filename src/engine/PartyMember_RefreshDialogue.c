#pragma thumb on
/* PartyMember_RefreshDialogue -- rebuild the dialogue record of member `slot` (1-based), MAIN. The member's
 * message record (+0x44) is released and rebuilt from message db 0x1e (MsgDb_FetchRecord, kind 5 with
 * `msgArg`) with the db pinned around it, then the member's flags (+0x4) are recomputed from two
 * progress queries (GameState_GetField): 0x37c7 gives 0 = record marked (+0x30), 1 = 0x800, 2 = 0x1;
 * 0x35bf gives 1 = 0x1000|0x200, 2 = 0x2; a member whose table entry (gPartyMembers, stride
 * 0x104, byte +3) is 0xe also gets 0x1 once flag 0x208c is set. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct PartyMsgRec {
    char pad00[0x30];
    int marked;                         /* +0x30 */
} PartyMsgRec;

typedef struct PartyMember {
    int pad00;
    unsigned int flags;                 /* +0x04 */
    char pad08[0x44 - 8];
    PartyMsgRec *msg;                   /* +0x44 */
} PartyMember;

typedef struct PartyEntry {
    u8 pad00[3];
    u8 kind;                            /* +0x03 */
    u8 pad04[0x104 - 4];
} PartyEntry;

extern PartyEntry gPartyMembers[];

void PartyMember_RefreshDialogue(int slot, int msgArg)
{
    PartyMember *member = (PartyMember *)GetPlayerSlotTableEntry(slot - 1);
    int state;

    MsgDb_LoadDb(0x1e, 2);
    if (member->msg != 0) {
        DispatchByNodeKind(&member->msg);
    }
    MsgDb_FetchRecord(&member->msg, 0x1e, msgArg, 5);
    ResSlot_Release_2(0x1e);
    state = GameState_GetField(0x37c7, 2);
    member->flags = 0;
    switch (state) {
    case 0:
        member->msg->marked = 1;
        break;
    case 1:
        member->flags |= 0x800;
        break;
    case 2:
        member->flags |= 1;
        break;
    }
    switch (GameState_GetField(0x35bf, 2)) {
    case 0:
        break;
    case 1:
        member->flags |= 0x1000;
        member->flags |= 0x200;
        break;
    case 2:
        member->flags |= 2;
        break;
    }
    if (((PartyEntry *)((u8 *)gPartyMembers + slot * sizeof(PartyEntry)))->kind == 0xe && GameState_IsFlagSet(0x208c)) {
        member->flags |= 1;
    }
}
