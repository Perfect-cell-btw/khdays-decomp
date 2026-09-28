/* Damps the velocity until almost still, then plays anim 10 and installs the end step. */

struct v3 { int a, b, c; };
extern void ScaleVec3Fx12();
extern int VEC_Mag();
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov244_AiStep_QueueAction2OnFlag0cClear(void);
void Ov244_AiBrakeToStop(int *node) {
    int *state = (int *)node[1];
    *(struct v3 *)(state + 0x14) = *(struct v3 *)(state + 0x17);
    ScaleVec3Fx12(0xb00, state + 0x17, state + 0x17);
    if (VEC_Mag(state + 0x17) >= 0x10) return;
    Ov107_PostTagUpdate(*state, 10, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov244_AiStep_QueueAction2OnFlag0cClear);
}
