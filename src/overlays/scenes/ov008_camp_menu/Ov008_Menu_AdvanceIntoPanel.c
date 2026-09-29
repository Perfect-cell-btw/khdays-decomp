/*
 * Ov008_Menu_AdvanceIntoPanel - one-shot handler that advances the current menu
 * context into sub-scene 8 (a detail panel) when the entry conditions are met.
 *
 * Gated on bit 7 of the context status halfword at +0x5c6 being clear (the "not
 * yet advanced" latch). While clear it runs the per-frame menu setup steps
 * (Ov008_Menu_RefreshSlotPanel / Ov008_Menu_RefreshSubitemGrid / Ov008_Menu_UpdateDirectionalPrompt), then, only
 * if all of the following hold, performs the advance:
 *   - game flag 0x200c is set;
 *   - bit 4 of the shared context (*data_ov008_02090f1c) status halfword is clear;
 *   - the cursor lookup Ov008_GetPlayerRecord(0) returns a record whose byte[3] == 8.
 * The advance primes sub-scene 8 from the cursor, stamps the sub-struct, sets the
 * 0x80 latch bit so it fires once, and points the target slot at duration 300.
 * The teardown/refresh at ctx+0x98 (Ov008_Menu_RenderScenePanels) always runs.
 *
 * The +0x5c6 bit tests use the (x << N) >> 31 shift form (bit 7 for N=24, bit 4
 * for N=27), matching the ROM's lsl/lsr pair rather than a tst mask.
 */

#include "game/engine.h"

extern void Ov008_Menu_RefreshSlotPanel(void);
extern void Ov008_Menu_RefreshSubitemGrid(void);
extern void Ov008_Menu_UpdateDirectionalPrompt(int obj);
extern int Ov008_GetPlayerRecord(int slot);
extern void Ov008_PrimeSubSceneFromCursor(int arg);
extern void Ov008_SetTargetSlot(int slot, unsigned int dur);
extern void Ov008_Menu_RenderScenePanels(int obj);
extern int data_ov008_02090f1c;

void Ov008_Menu_AdvanceIntoPanel(int param_1, int param_2, int param_3, int param_4)
{
    int r;

    if ((((unsigned int)*(unsigned short *)(param_1 + 0x5c6) << 0x18) >> 0x1f) == 0) {
        Ov008_Menu_RefreshSlotPanel();
        Ov008_Menu_RefreshSubitemGrid();
        Ov008_Menu_UpdateDirectionalPrompt(param_1);
        if (GameState_IsFlagSet(0x200c) != 0 &&
            (((unsigned int)*(unsigned short *)(data_ov008_02090f1c + 0x5c6) << 0x1b) >> 0x1f) == 0 &&
            (r = Ov008_GetPlayerRecord(0)) != 0 &&
            *(unsigned char *)(r + 3) == 8) {
            Ov008_PrimeSubSceneFromCursor(8);
            StampByteAndInvokeSubStructAt(1, 4);
            *(unsigned short *)(param_1 + 0x5c6) |= 0x80;
            Ov008_SetTargetSlot(-1, 300);
        }
    }
    Ov008_Menu_RenderScenePanels(param_1 + 0x98);
}
