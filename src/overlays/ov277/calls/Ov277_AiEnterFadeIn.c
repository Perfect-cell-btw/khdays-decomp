/* Play the anim (ov107 mode 5), reset the timer (+0x44) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov277_FadeInSubObject(int);
void Ov277_AiEnterFadeIn(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 5, 0);
    *(int *)(child + 0x44) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov277_FadeInSubObject);
}
