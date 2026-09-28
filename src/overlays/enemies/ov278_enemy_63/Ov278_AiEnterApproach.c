/* Set the target rate (+0x28 = owner_rate*30/10), set *(*child)+0x54 = 0x3000, clear +0x14,
 * roll +0x3c = rand(0x3001) + 0x2000 and register the handler. */
extern int RandNextScaled(int a);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov278_ApproachTick(int);
void Ov278_AiEnterApproach(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x28) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 10;
    *(int *)(*(int *)child + 0x54) = 0x3000;
    *(int *)(child + 0x14) = 0;
    *(int *)(child + 0x3c) = RandNextScaled(0x3001) + 0x2000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov278_ApproachTick);
}
