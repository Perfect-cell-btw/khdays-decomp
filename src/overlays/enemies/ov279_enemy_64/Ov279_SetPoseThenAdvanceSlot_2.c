/* Push animation params (1, 1) to the sprite, then dispatch via
 * SetIndexedSlot with handler Ov279_TickApproachTarget. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov279_TickApproachTarget(void);
void Ov279_SetPoseThenAdvanceSlot_2(int param_1) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(param_1 + 4)), 1, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov279_TickApproachTarget);
}
