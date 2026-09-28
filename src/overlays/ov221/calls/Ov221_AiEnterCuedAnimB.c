/* Reset the child sprite (anim 0xf, clear +0x5c word and +0x75 flag), then
 * dispatch via SetIndexedSlot (handler Ov221_AiCuedAnimTickB). */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov221_AiCuedAnimTickB(void);
void Ov221_AiEnterCuedAnimB(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 0xf, 0);
    *(int *)(child + 0x5c) = 0;
    *(unsigned char *)(child + 0x75) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov221_AiCuedAnimTickB);
}
