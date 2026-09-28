/* Play the anim (ov107 mode 0,1), clear +0x24 and set +0x14 = rand(0x3001) + 0x2000, then
 * register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int RandNextScaled(int a);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov278_AiSeekTick_2(int);
void Ov278_AiEnterSeek_2(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 0, 1);
    *(int *)(child + 0x24) = 0;
    *(int *)(child + 0x14) = RandNextScaled(0x3001) + 0x2000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov278_AiSeekTick_2);
}
