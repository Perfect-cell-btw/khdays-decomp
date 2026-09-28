/* AI step: posts pose 3, turns towards the target and continues with decelerating. */

extern void Ov107_PostTagUpdate();
extern void VEC_Subtract(void *a, void *b, void *out);
extern int func_020050b4(int x, int z);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov131_AiDecelUntilFlagClear(void);

void Ov131_stateAnimAimAtTarget(char *obj) {
    int *state = *(int **)(obj + 4);
    int v[3];
    Ov107_PostTagUpdate(*state, 3, 0);
    if (state[0xe] != 0) {
        int a;
        VEC_Subtract((void *)(state[0xe] + 0x190), (void *)(*state + 0xb0), v);
        a = func_020050b4(v[0], v[2]);
        state[4] = a;
        state[3] = a;
    }
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov131_AiDecelUntilFlagClear);
}
