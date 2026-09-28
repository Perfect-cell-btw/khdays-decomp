/* Unless the busy byte at *(child+0x20) is set, play the anim (ov107 mode 9), clear +0x18 and
 * the +0x74 byte and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov236_StompTick(int);
void Ov236_RidersB_AiEnterStomp(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(child + 0x20) != 0) return;
    Ov107_PostTagUpdate(*(int *)child, 9, 0);
    *(int *)(child + 0x18) = 0;
    *(signed char *)(child + 0x74) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov236_StompTick);
}
