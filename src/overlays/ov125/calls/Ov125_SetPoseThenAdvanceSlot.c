/* Push animation params (1, 1) to the sprite, then dispatch via
 * SetIndexedSlot with handler Ov125_ChooseMove. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov125_ChooseMove(void);
void Ov125_SetPoseThenAdvanceSlot(int param_1) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(param_1 + 4)), 1, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov125_ChooseMove);
}
