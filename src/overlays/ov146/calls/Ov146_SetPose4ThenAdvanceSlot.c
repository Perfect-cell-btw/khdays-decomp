/* Push animation params (4, 0) to the sprite, then dispatch via
 * SetIndexedSlot with handler Ov146_AiEnterFace. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov146_AiEnterFace(void);
void Ov146_SetPose4ThenAdvanceSlot(int param_1) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(param_1 + 4)), 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_AiEnterFace);
}
