/* Ov254_HelperCMoveDispatch -- move dispatcher of an ov254 helper: a pending move (+0x1c7 != -1) becomes
 * current (+0x1c6), bit 0 of the actor's +0x60 high byte is set and bit 7 cleared, and the handler
 * of move 0 / 1 / 2 (020d5790 / 020d5800 / 020d5884) is registered in slot 1; the pending slot is
 * then reset to -1. */
typedef unsigned short u16;
struct Hw60 { u16 lo : 8; u16 hi : 8; };

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov254_TwinMarker_AiEnterIdle(void);
extern void Ov254_MountEntry(void);
extern void Ov254_ResetAiSlotsAndRearm(void);

void Ov254_HelperCMoveDispatch(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) == -1) {
        return;
    }
    *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
    {
        u16 hw = *(u16 *)(ctx[0] + 0x60);
        *(u16 *)(ctx[0] + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 1) << 0x18) >> 0x10);
    }
    ((struct Hw60 *)(ctx[0] + 0x60))->hi &= ~0x80;
    switch (*(signed char *)(ctx[0] + 0x1c6)) {
    case 0:
        SetIndexedSlot(self, 1, Ov254_TwinMarker_AiEnterIdle);
        break;
    case 1:
        SetIndexedSlot(self, 1, Ov254_MountEntry);
        break;
    case 2:
        SetIndexedSlot(self, 1, Ov254_ResetAiSlotsAndRearm);
        break;
    }
    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
