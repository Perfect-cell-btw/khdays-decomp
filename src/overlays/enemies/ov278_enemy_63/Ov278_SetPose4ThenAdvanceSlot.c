/* Push animation params (4, 0) to the sprite, then dispatch via
 * SetIndexedSlot with handler Ov278_AiFaceForwardQueue9. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov278_AiFaceForwardQueue9(void);
void Ov278_SetPose4ThenAdvanceSlot(int param_1) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(param_1 + 4)), 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov278_AiFaceForwardQueue9);
}
