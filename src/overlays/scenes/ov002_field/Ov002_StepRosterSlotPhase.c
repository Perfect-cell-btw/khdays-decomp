/* Advance the session phase for one roster slot, applying that slot on the way. Returns whether
 * the caller may continue this frame.
 *
 * A slot index of -1 means the currently active slot, which comes from QueryActiveStateOrDelegate. Nothing
 * happens while the session's leading word is -1 or while the party entry for the slot does not
 * exist; both answer yes.
 *
 * The slot lives in the roster array reached through session+4, indexed by 0x44. Its seat id at
 * +0x10 resolves through Ov002_GetCtxTableByte, or is taken as zero when the id is -1, and the value
 * at +0xc rides along to the two apply calls.
 *
 * For the ACTIVE slot the phase at session+0xc0 drives a five-way switch, gated first by the byte
 * at data_0204be04: phases below three require it clear and phases from three up require it set,
 * otherwise the answer is no. Phases 0 and 3 apply the seat, push the slot, refill its defaults,
 * advance to 2 or 5 and record the seat at session+0xc4; if that seat has a node they also dispatch
 * it and fall back to phase 1 or 4 answering no. Phases 1 and 4 wait on the recorded seat's node,
 * reading a four-bit field at node+0xf8, and advance to 2 or 5 once it reads zero. Any other phase
 * falls through unchanged. For a non-active slot it just applies, pushes, refills and dispatches,
 * always answering yes.
 *
 * Codegen notes, all four measured. func_ov022_020883d4 takes TWO arguments and the second is the
 * node just fetched, which is why the ROM moves the call result with a flag-setting add instead of
 * comparing it; declaring one argument costs four bytes. The third argument of Ov002_ApplyRosterSlotToNode
 * is a plain word, not a short, so nothing sign-extends. The phase ternaries are written positively
 * as >= 3 giving 5 else 2, which puts the branches the ROM's way round. And the slot address is
 * built in two steps with the offset materialised first: every one-expression spelling of it,
 * including an explicit offset local, costs twenty-two bytes because mwcc then loads the table
 * pointer before the multiply.
 *
 * Ghidra carries this as Ov002_StepRosterSlotPhase over Ov002RosterSlot and Ov002SessionBlock.
 */

#include "game/engine.h"

extern char *data_ov002_0207fa00;
extern unsigned char data_0204be04;

extern int Ov002_GetCtxTableByte(int seatId);
extern void func_ov022_02088428(int index, int seat);
extern void Ov002_ApplyRosterSlotToNode(int index, void *slot, int value);
extern void Ov022_BroadcastCue(int index, int seat, void *slot, int value);
extern void Ov002_FillRosterSlotDefaults(int index);
extern int Ov002_GetPieceOwner(int seat);
extern void func_ov022_020883d4(int index, int node);

int Ov002_StepRosterSlotPhase(int index) {
    char *session = data_ov002_0207fa00 + 0x8bcc;
    int result = 1;
    int value;
    char *slot;
    int seatId;
    int node;
    int seat;

    if (index == -1) {
        index = QueryActiveStateOrDelegate();
    }
    if (*(int *)session == -1) {
        return 1;
    }
    if (GetEntryField20ByIndex(index) == 0) {
        return 1;
    }

    slot = (char *)(index * 0x44);
    slot = *(char **)(session + 4) + (int)slot;
    seatId = *(int *)(slot + 0x10);
    value = *(int *)(slot + 0xc);
    if (seatId == -1) {
        seat = 0;
    } else {
        seat = Ov002_GetCtxTableByte(seatId);
    }

    if (index == QueryActiveStateOrDelegate()) {
        if (*(int *)(session + 0xc0) < 3) {
            if (data_0204be04 != 0) {
                return 0;
            }
        } else if (data_0204be04 == 0) {
            return 0;
        }

        switch (*(int *)(session + 0xc0)) {
        case 0:
        case 3:
            func_ov022_02088428(index, seat);
            Ov002_ApplyRosterSlotToNode(index, slot, value);
            Ov022_BroadcastCue(index, seat, slot, value);
            Ov002_FillRosterSlotDefaults(index);
            *(int *)(session + 0xc0) = (*(int *)(session + 0xc0) >= 3) ? 5 : 2;
            *(int *)(session + 0xc4) = seat;
            if ((node = Ov002_GetPieceOwner(seat)) != 0) {
                func_ov022_020883d4(index, node);
                *(int *)(session + 0xc0) =
                    (*(int *)(session + 0xc0) >= 3) ? 4 : 1;
                result = 0;
            }
            break;
        case 1:
        case 4:
            {
                int obj = Ov002_GetPieceOwner(*(int *)(session + 0xc4));

                GetEntryField20ByIndex(index);
                result = 0;
                if ((*(int *)(obj + 0xf8) << 0x1c) >> 0x1c == 0) {
                    *(int *)(session + 0xc0) =
                        (*(int *)(session + 0xc0) >= 3) ? 5 : 2;
                    result = 1;
                }
            }
            break;
        }
    } else {
        func_ov022_02088428(index, seat);
        Ov002_ApplyRosterSlotToNode(index, slot, value);
        Ov002_FillRosterSlotDefaults(index);
        if ((node = Ov002_GetPieceOwner(seat)) != 0) {
            func_ov022_020883d4(index, node);
        }
        result = 1;
    }
    return result;
}
