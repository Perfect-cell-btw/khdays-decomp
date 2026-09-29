/* Set anim (1 if child+0x78 else 3), set +0x5c = 0x1000, then dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov221_AiCooldownTick(void);
void Ov221_AiEnterCooldown(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, *(int *)(child + 0x78) != 0 ? 1 : 3, 0);
    *(int *)(child + 0x5c) = 0x1000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov221_AiCooldownTick);
}
