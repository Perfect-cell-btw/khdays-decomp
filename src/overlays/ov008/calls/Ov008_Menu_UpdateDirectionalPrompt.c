/*
 * Ov008_Menu_UpdateDirectionalPrompt - recompute the menu's directional-prompt
 * state and, when it changes, redraw the on-screen prompt text.
 *
 * Reads the current prompt state from the sub-block at +0x5c0, then selects a new
 * state (0x16..0x1c) from an input/branch decision tree:
 *   ed3c != 0 (a mode is active):
 *     ebf0 == 0            -> keep state unless it is 0x19/0x1a, else 0x17
 *     ebf0 != 0, 570c0 == 0 -> 0x19   ; != 0 -> 0x1a
 *   ed3c == 0:
 *     ebf0 == 0            -> 0x1b
 *     ebf0 != 0, flag 0x200c clear -> 0x16 ; set -> 0x18
 * Bit 4 of the shared context status halfword (*data_ov008_02090f1c + 0x5c6)
 * overrides the result to 0x1c. If the state actually changed it is written back,
 * the object's inner vtable is fired (Obj_InvokeInnerVtable4), the matching text record is
 * fetched (Ov008_GetVarRecordByIndex) and two directional strings are drawn
 * (Text_DrawDirectional_2, ids 0xff/0xfe) before the gfx command is enqueued.
 *
 * Codegen notes:
 *  - The +0x5c6 test is a 16-bit bitfield (f->b4), not a manual (x<<N)>>31 shift;
 *    both emit ldrh;lsl;lsr but only the bitfield coalesces the container into the
 *    field register the way the ROM does.
 *  - `cur` (the preserved original state) is declared BEFORE `next` even though
 *    `next` receives the load first: mwcc colours locals in declaration order
 *    (cur->r4, next->r5), which makes the ldrh target next(r5) directly and copy
 *    to cur(r4) - matching the ROM. Declaring next first colours it r4 and adds a
 *    stray register swap at the first byte.
 */

extern int Ov008_IsSessionReady(void);
extern int Ov008_IsBusy(void);
extern int Ov008_AreSelectedMenuSlotsReady(void);
extern int GameState_IsFlagSet(int flag);
extern void Obj_InvokeInnerVtable4(int obj);
extern int Ov008_GetVarRecordByIndex(int recs, int index);
extern void Text_DrawDirectional_2(int self, int x, int y, int p4, unsigned int flags, int rec);
extern void EnqueueObjGfxCommand(int obj);
extern int data_ov008_02090f1c;

typedef struct {
    unsigned short b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1,
                   b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, b15:1;
} Flags;

void Ov008_Menu_UpdateDirectionalPrompt(int param_1, int param_2, int param_3, int param_4)
{
    unsigned short cur;
    unsigned short next = *(unsigned short *)(param_1 + 0x5c0);
    int rec;
    cur = next;

    if (Ov008_IsSessionReady() != 0) {
        if (Ov008_IsBusy() == 0) {
            if (next != 0x19 && next != 0x1a) next = 0x17;
        } else if (Ov008_AreSelectedMenuSlotsReady() == 0) {
            next = 0x19;
        } else {
            next = 0x1a;
        }
    } else {
        if (Ov008_IsBusy() == 0) {
            next = 0x1b;
        } else if (GameState_IsFlagSet(0x200c) == 0) {
            next = 0x16;
        } else {
            next = 0x18;
        }
    }
    if (((Flags *)(data_ov008_02090f1c + 0x5c6))->b4) next = 0x1c;
    if (cur != next) {
        *(short *)(param_1 + 0x5c0) = next;
        Obj_InvokeInnerVtable4(param_1 + 0x10);
        rec = Ov008_GetVarRecordByIndex(param_1 + 4, *(unsigned short *)(param_1 + 0x5c0));
        Text_DrawDirectional_2(param_1 + 0x10, 0xff, 3, 1, 0x821, rec);
        Text_DrawDirectional_2(param_1 + 0x10, 0xfe, 2, 2, 0x821, rec);
        EnqueueObjGfxCommand(param_1 + 0x10);
    }
}
