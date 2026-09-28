/* Store the scaled approach delta into +0x10, advance the +0x44 timer, and dispatch once it expires. */
extern int Ov254_PanelYForPhase(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov254_LandingTick(int);
void Ov254_AiSettleTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int base = Ov254_PanelYForPhase(owner, -1);
    int v = *(int *)(*(int *)(owner + 8) + 4);
    *(int *)(owner + 0x10) = (int)((((long long)(base - v) << 7) + 0x800) >> 12);
    *(int *)(owner + 0x44) += *(int *)(*(int *)param_1 + 0x2c);
    if (*(int *)(owner + 0x44) < 0xa000) return;
    *(signed char *)(*(int *)(owner + 4) + 0xa8) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_LandingTick);
}
