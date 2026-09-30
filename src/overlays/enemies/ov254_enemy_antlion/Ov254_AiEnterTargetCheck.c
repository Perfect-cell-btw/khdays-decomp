/* Kick anim (0 if +0x78 set else 0xb), then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov254_AiTargetCheckTick(int);
void Ov254_AiEnterTargetCheck(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, *(int *)(owner + 0x78) != 0 ? 0 : 0xb, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_AiTargetCheckTick);
}
