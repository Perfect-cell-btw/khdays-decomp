/* Push animation params (4, 0) to the sprite, then dispatch via
 * SetIndexedSlot with handler Ov180_HoverTick. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov180_HoverTick(void);
void Ov180_SetPose4ThenAdvanceSlot(int param_1) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(param_1 + 4)), 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov180_HoverTick);
}
