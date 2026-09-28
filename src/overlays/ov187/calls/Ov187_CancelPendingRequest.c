/*
 * Ov187_CancelPendingRequest -- x3 (ov185/186/187). If a pending request is queued and its mode is not one
 * of the "keep" modes, cancel it. If *(self+0x400) != 0, read the mode byte *(s8)(self+0x1c6): when
 * it is not 2, 4 or 5, run 020cb100(*(self+0x400)) and clear the slot. Always tick 020c7ca4(self).
 * (The 2nd incoming arg is unused -- the original reuses that register as the mode scratch.)
 */
extern void Ov107_UnlinkNodeFromOwner(int req);
extern void Ov107_AiState_PostTickBase(int self);

void Ov187_CancelPendingRequest(int self, int arg) {
    int req = *(int *)(self + 0x400);

    if (req != 0) {
        signed char mode = *(signed char *)(self + 0x1c6);
        if (mode != 2 && mode != 4 && mode != 5) {
            Ov107_UnlinkNodeFromOwner(req);
            *(int *)(self + 0x400) = 0;
        }
    }
    Ov107_AiState_PostTickBase(self);
}
