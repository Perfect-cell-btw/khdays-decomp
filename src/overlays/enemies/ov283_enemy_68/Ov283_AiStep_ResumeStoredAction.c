/* If active: rolls the move timer, resets the counters and queues the stored action. */

extern unsigned int RandNextScaled(unsigned int range);
extern int Ov283_ForwardToAiTaskWhenReady(int param_1, int param_2);
extern void SetIndexedSlot(int *a, int i, int v);

struct hw60lo_020cd170 { unsigned short lo : 8; unsigned short hi : 8; };

void Ov283_AiStep_ResumeStoredAction(int param_1) {
    int child = *(int *)(param_1 + 4);
    int obj = *(int *)child;
    int base, d, i;

    if ((((struct hw60lo_020cd170 *)(obj + 0x60))->lo & 1) == 0) return;

    base = *(int *)(obj + 0x224);
    d = *(int *)(obj + 0x228) - base;
    if (d < 0) d = -d;
    *(int *)(child + 0x4c) = base + RandNextScaled(d + 1);
    *(int *)(child + 0x54) = 0;

    for (i = 0; i < 2; i++) {
        obj = *(int *)child;
        Ov283_ForwardToAiTaskWhenReady(((int *)obj)[i + 0x39c / 4], ((int *)obj)[i + 0x394 / 4]);
    }

    obj = *(int *)child;
    *(signed char *)(obj + 0x1c7) = *(signed char *)(obj + 0x1c9);
    SetIndexedSlot((int *)param_1, *(signed char *)(param_1 + 0x20), 0);
}
