/* Notify Ov227_SetMode with the child fields, then dispatch. */
extern void Ov227_SetMode(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov227_AiApproachTick(void);
void Ov227_AiEnterApproach(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov227_SetMode(*(int *)child, *(int *)(child + 0x78));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov227_AiApproachTick);
}
