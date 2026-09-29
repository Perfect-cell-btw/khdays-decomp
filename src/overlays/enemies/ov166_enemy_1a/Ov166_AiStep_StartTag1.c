/* AI step: Ov107_PostTagUpdate(actor, 1, 1), clears context +0x48 and installs the next step
 * handler. */

extern void Ov107_PostTagUpdate(int v, int a, int b);
extern void SetIndexedSlot(void *a, int b, void *cb);
extern void Ov166_HoverApproachTick(void);

void Ov166_AiStep_StartTag1(char *a) {
    char *p = *(char **)(a + 0x4);
    Ov107_PostTagUpdate(*(int *)p, 1, 1);
    *(int *)(p + 0x48) = 0;
    SetIndexedSlot(a, *(signed char *)(a + 0x20), Ov166_HoverApproachTick);
}
