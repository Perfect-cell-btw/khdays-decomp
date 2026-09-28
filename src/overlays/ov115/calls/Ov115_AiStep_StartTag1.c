extern void Ov107_PostTagUpdate(int v, int a, int b);
extern void SetIndexedSlot(void *a, int b, void *cb);
extern void Ov115_HoverApproachTick(void);

void Ov115_AiStep_StartTag1(char *a) {
    char *p = *(char **)(a + 0x4);
    Ov107_PostTagUpdate(*(int *)p, 1, 1);
    *(int *)(p + 0x48) = 0;
    SetIndexedSlot(a, *(signed char *)(a + 0x20), Ov115_HoverApproachTick);
}
