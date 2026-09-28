/* Ov256_HelperMoveDispatch -- move dispatcher of an ov256 helper: a pending move (+0x1c7 != -1) becomes
 * current (+0x1c6) and its handler (020d1994 / 020d1a40 / 020d1b7c / 020d2054 for moves 0-3) is
 * registered in slot 1; the pending slot is always reset to -1. */
extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov256_HelperStopEntry(void);
extern void Ov256_ArmEntry(void);
extern void Ov256_ClawLaunchEntry(void);
extern void Ov256_ClawAimEntry(void);

void Ov256_HelperMoveDispatch(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
    *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
    switch (*(signed char *)(ctx[0] + 0x1c6)) {
    case 0:
        SetIndexedSlot(self, 1, Ov256_HelperStopEntry);
        break;
    case 1:
        SetIndexedSlot(self, 1, Ov256_ArmEntry);
        break;
    case 2:
        SetIndexedSlot(self, 1, Ov256_ClawLaunchEntry);
        break;
    case 3:
        SetIndexedSlot(self, 1, Ov256_ClawAimEntry);
        break;
    }
    }
    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
