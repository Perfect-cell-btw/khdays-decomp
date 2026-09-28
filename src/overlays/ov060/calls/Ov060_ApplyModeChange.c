/*
 * Apply a mode change to the actor (x4: ov041/060/078/095).
 *
 * A sparse switch on the absolute mode: 0x2e does nothing; 0x2f rewinds the first sub-object
 * (020b3c70 on the block at self+0x2c84) and clears the selector at +0x664; 0x30 rewinds the
 * second (+0x110), re-arms the third (020b42a0 on +0x220) and sets the selector to 1. Both arms
 * no-op when the mode did not change (+0x6bc caches it). Then 020a384c hands the mode down and
 * the UI band gets it translated (020519b0 -> 02052024) at/above 0x2e, or straight (020521a4)
 * below.
 *
 * Off the ov034/ov046 template. Two things the ROM insists on:
 *  - `case 0x2e: break;` is a REAL empty case, not a missing one -- the compare chain tests it
 *    and branches to the exit. See Ov036_ApplyModeChange.c for the extreme form of this, where
 *    the empty cases leave dead compares behind.
 *  - the loop flag is computed BEFORE the `mode >= 0x2e` branch, not inside the arm that uses
 *    it. Every member of this family does that, and it is worth two instructions: computed
 *    inside the arm, mwcc reorders the whole tail.
 */
extern void Ov060_Activate(int *p);
extern void Ov060_BindAnimsMode2(int *p);
extern void Ov022_SetAnimState(int self, int mode);
extern int Ov002_GetModeBlendFrames(int a, int b, int c);
extern void Ov002_ApplyAnimMode(void *a, int b, int c, int d, int e);
extern void Ov002_DrawEntryWithPalette(void *a, int b, int c, int d);

void Ov060_ApplyModeChange(int self, int mode) {
    int p = self + 0x2c84;
    int flag;
    int ret;

    switch (mode) {
    case 0x2e:
        break;
    case 0x2f:
        if (*(int *)(self + 0x6bc) != mode) {
            Ov060_Activate((int *)p);
            *(int *)(p + 0x664) = 0;
        }
        break;
    case 0x30:
        if (*(int *)(self + 0x6bc) != mode) {
            Ov060_Activate((int *)(p + 0x110));
            Ov060_BindAnimsMode2((int *)(p + 0x220));
            *(int *)(p + 0x664) = 1;
        }
        break;
    }
    Ov022_SetAnimState(self, mode);
    flag = 0;
    if (*(signed char *)(self + 0x2bb2) == 2) { flag = 1; }
    if (mode >= 0x2e) {
        ret = Ov002_GetModeBlendFrames(mode, *(int *)(self + 0x6bc), *(int *)(self + 0xc));
        Ov002_ApplyAnimMode((void *)(self + 0xf0c), self + 0x2c30, mode, 2, ret);
        return;
    }
    Ov002_DrawEntryWithPalette((void *)(self + 0xf0c), self + 0x2c30, mode, flag);
}
