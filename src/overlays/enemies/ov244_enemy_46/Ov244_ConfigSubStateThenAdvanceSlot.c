/* Play the anim (ov107 mode 0xb), fire ov107_020c5af8(*child, 0x112, 4, *(child+4)), clear
 * +0x44 and the +0x49 byte and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov244_AiSwingTick(int);
void Ov244_ConfigSubStateThenAdvanceSlot(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 0xb, 0);
    Ov107_BuildAndSendUpdate(*(int *)child, 0x112, 4, *(int *)(child + 4));
    *(int *)(child + 0x44) = 0;
    *(signed char *)(child + 0x49) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov244_AiSwingTick);
}
