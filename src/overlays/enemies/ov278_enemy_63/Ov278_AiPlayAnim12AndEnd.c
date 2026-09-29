/* Play the anim (ov107 mode 0xc) on *child and dispatch (no handler). */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov278_AiPlayAnim12AndEnd(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 0xc, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
