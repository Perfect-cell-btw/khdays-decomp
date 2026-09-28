/*
 * Ov008_Menu_CommitEnterSubScene8 - confirm/commit path that advances the shared
 * menu context into detail sub-scene 8, latching the persistent state.
 *
 * Bails while bit 4 or bit 5 of the shared context status halfword (+0x5c6) is
 * set, while the two subsystem gates (Ov008_PageB_GetBusy / Ov008_PageB_HasPending)
 * report busy, and unless the input branch is satisfied: when Ov008_IsSessionReady
 * is non-zero it requires Ov008_AreSelectedMenuSlotsReady, otherwise it requires
 * Ov008_IsBusy. On success it plays the confirm sound only the first time
 * (game flag 0x200c not yet set), refreshes menu button 5, runs the pre-commit
 * step Ov008_SetActivePage(0), latches bit 8 (0x100) at +0x5c6, sets the
 * persistent game flag 0x200c, and primes sub-scene 8 from the cursor.
 *
 * Codegen note: the +0x5c6 bit accesses are a 16-bit bitfield, NOT a manual
 * `(x << N) >> 31` shift. Both forms emit the same `ldrh; lsl; lsr` triple, but
 * only the bitfield IR coalesces the CSE'd container into the field's own
 * register (r0) the way the ROM does; the manual-shift form colors it into a
 * scratch register (r1) and diverges at the first bit test.
 */

extern int Ov008_PageB_GetBusy(void);
extern int Ov008_PageB_HasPending(void);
extern int Ov008_IsSessionReady(void);
extern int Ov008_AreSelectedMenuSlotsReady(void);
extern int Ov008_IsBusy(void);
extern int GameState_IsFlagSet(int flag);
extern void PlaySound(int a, int b);
extern void Ov008_UpdateMenuButton5(int a);
extern void Ov008_SetActivePage(int a);
extern void GameState_SetFlag(int flag);
extern void Ov008_PrimeSubSceneFromCursor(int arg);
extern int data_ov008_02090f1c;

typedef struct {
    unsigned short b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1,
                   b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, b15:1;
} Flags;

void Ov008_Menu_CommitEnterSubScene8(void)
{
    Flags *f = (Flags *)(data_ov008_02090f1c + 0x5c6);

    if (f->b4) return;
    if (f->b5) return;
    if (Ov008_PageB_GetBusy() != 0) return;
    if (Ov008_PageB_HasPending() != 0) return;
    if (Ov008_IsSessionReady() != 0) {
        if (Ov008_AreSelectedMenuSlotsReady() == 0) return;
    } else {
        if (Ov008_IsBusy() == 0) return;
    }
    if (GameState_IsFlagSet(0x200c) == 0) PlaySound(0, 1);
    Ov008_UpdateMenuButton5(0);
    Ov008_SetActivePage(0);
    ((Flags *)(data_ov008_02090f1c + 0x5c6))->b8 = 1;
    GameState_SetFlag(0x200c);
    Ov008_PrimeSubSceneFromCursor(8);
}
