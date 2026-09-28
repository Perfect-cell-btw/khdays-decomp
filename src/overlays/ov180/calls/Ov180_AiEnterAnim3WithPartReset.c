/* Resets the part, plays anim 3 and installs the next step. */

extern void SetIndexedSlot();
extern void Ov180_ForwardToAiTaskWhenReady();
extern void Ov107_PostTagUpdate();
extern void Ov180_HoverTick(void);
void Ov180_AiEnterAnim3WithPartReset(int node) {
    int *s = *(int **)(node + 4);
    Ov180_ForwardToAiTaskWhenReady(*(int *)(*s + 0x3ac));
    Ov107_PostTagUpdate(*s, 3, 0);
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov180_HoverTick);
}
