/* Ov254_HelperMoveDispatch -- move dispatcher of an ov254 helper: a pending move (+0x1c7 != -1) becomes
 * current (+0x1c6) and its handler (020d5190 / 020d5200 / 020d5278 / 020d52dc for moves 0-3) is
 * registered in slot 1; the pending slot is then reset to -1. */
extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov254_Marker_AiEnterIdle(void);
extern void Ov254_Marker_AiEnterPlay(void);
extern void Ov254_SetPose2ThenAdvanceSlot_2(void);
extern void Ov254_Marker_AiPlayStoredAnim(void);

void Ov254_HelperMoveDispatch(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) == -1) {
        return;
    }
    *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
    switch (*(signed char *)(ctx[0] + 0x1c6)) {
    case 0:
        SetIndexedSlot(self, 1, Ov254_Marker_AiEnterIdle);
        break;
    case 1:
        SetIndexedSlot(self, 1, Ov254_Marker_AiEnterPlay);
        break;
    case 2:
        SetIndexedSlot(self, 1, Ov254_SetPose2ThenAdvanceSlot_2);
        break;
    case 3:
        SetIndexedSlot(self, 1, Ov254_Marker_AiPlayStoredAnim);
        break;
    }
    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
