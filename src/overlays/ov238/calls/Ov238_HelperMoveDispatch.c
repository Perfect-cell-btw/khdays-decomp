/* Ov238_HelperMoveDispatch -- move dispatcher of an ov238 helper: a pending move (+0x1c7 != -1) becomes
 * current (+0x1c6) and its handler (020d2c44 / 020d2d08 / 020d2e30 / 020d30b8 for moves 0-3) is
 * registered in slot 1; the pending slot is always reset to -1. */
extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov238_EnterReaction(void);
extern void Ov238_WakeEntry(void);
extern void Ov238_AiEnterCircle(void);
extern void Ov238_CollapseEntry(void);

void Ov238_HelperMoveDispatch(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
    *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
    switch (*(signed char *)(ctx[0] + 0x1c6)) {
    case 0:
        SetIndexedSlot(self, 1, Ov238_EnterReaction);
        break;
    case 1:
        SetIndexedSlot(self, 1, Ov238_WakeEntry);
        break;
    case 2:
        SetIndexedSlot(self, 1, Ov238_AiEnterCircle);
        break;
    case 3:
        SetIndexedSlot(self, 1, Ov238_CollapseEntry);
        break;
    }
    }
    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
