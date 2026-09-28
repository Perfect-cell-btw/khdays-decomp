/* Play the anim (ov107 mode 0xb), reset the timer (+0x24) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov207_FireAttack2OnIdle(int);
void Ov207_AiEnterAttack2(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 0xb, 0);
    *(int *)(child + 0x24) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov207_FireAttack2OnIdle);
}
