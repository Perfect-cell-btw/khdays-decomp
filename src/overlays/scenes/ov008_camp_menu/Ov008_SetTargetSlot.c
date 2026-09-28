/* Set the menu's target slot and start the cursor move. Records the target at +0x95c4 of the
 * shared screen context. With no slot active yet (cur == -1) it just snaps and flags dirty;
 * otherwise it animates -- mode 4, a cursor tween over `dur` frames (defaulting to 100 when
 * negative) -- and flags dirty only if the target is not where the cursor already is.
 *
 * Parked as a CSE tie: the original reloads the context pointer from the literal pool in each
 * store branch while mwcc cached it in a callee-saved register, eight bytes short. The fix is
 * the spelling of the global read. `*(int *)((int)data + 4)` is one expression that mwcc is
 * free to reuse; `data[1]` is an array subscript and comes out as a fresh pool load every time,
 * which is what the original has. Same lever as Ov008_FlushDirtyCells. */
extern int  func_ov008_02051aa0(void);
extern void Ov008_SetCtxField95cc(int mode);
extern void Ov008_BlitConfigRegion(int from, unsigned int dur);
extern void Ov008_EnableBothHalves(int a);
extern int  data_ov008_02090f04[];   /* [1] -> shared screen context */

void Ov008_SetTargetSlot(int slot, unsigned int dur) {
    int cur = func_ov008_02051aa0();
    *(int *)((char *)data_ov008_02090f04[1] + 0x95c4) = slot;
    if (cur == -1) {
        Ov008_SetCtxField95cc(1);
        *(int *)((char *)data_ov008_02090f04[1] + 0x95f8) = 1;
        return;
    }
    if ((int)dur < 0) {
        dur = 100;
    }
    Ov008_SetCtxField95cc(4);
    Ov008_BlitConfigRegion(-0x10, dur);
    Ov008_EnableBothHalves(0);
    if (cur == slot) {
        return;
    }
    *(int *)((char *)data_ov008_02090f04[1] + 0x95f8) = 1;
}
