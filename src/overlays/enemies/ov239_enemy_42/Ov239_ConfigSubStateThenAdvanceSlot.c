/* AI step: posts a pose, starts the matching animation and continues with the given step. */

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_StartAnim(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *value);

void Ov239_ConfigSubStateThenAdvanceSlot(int *node, int arg1, int arg2, int arg3, void *next) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, arg1, arg3);
    Ov107_StartAnim(*(int *)(*state + 0x398), arg2, arg3);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), next);
}
