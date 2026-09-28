/* Play the hit anim (ov107 mode 0x1a), set the recovery timer (+0x4c=0x13a8, +0x48=0)
 * and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov233_EmitChildOnRing(int);
void Ov233_AiEnterEmitRing(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 0x1a, 0);
    *(int *)(child + 0x4c) = 0x13a8;
    *(int *)(child + 0x48) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov233_EmitChildOnRing);
}
