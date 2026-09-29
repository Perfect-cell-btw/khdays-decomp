/* Set the target rate (+0x60 = owner_rate*30/30); unless the busy byte at *(child+4)+0xad
 * is set, pose the main node (ov107 mode 2,1) and the sub-node at (*child)+0x3ac (mode 0,1),
 * then register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_StartAnim(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov208_AimSteerDotGate(int);
void Ov208_AiAimStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x60) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 30;
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)child, 2, 1);
    Ov107_StartAnim(*(int *)(*(int *)child + 0x3ac), 0, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov208_AimSteerDotGate);
}
