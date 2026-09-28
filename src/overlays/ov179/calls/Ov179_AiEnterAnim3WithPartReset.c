extern void SetIndexedSlot();
extern void Ov179_ForwardToAiTaskWhenReady();
extern void Ov107_PostTagUpdate();
extern void Ov179_HoverTick(void);
void Ov179_AiEnterAnim3WithPartReset(int node) {
    int *s = *(int **)(node + 4);
    Ov179_ForwardToAiTaskWhenReady(*(int *)(*s + 0x3ac));
    Ov107_PostTagUpdate(*s, 3, 0);
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov179_HoverTick);
}
