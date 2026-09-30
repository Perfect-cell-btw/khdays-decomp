/* Spawn the child via 020cab14; once present clear its gate byte and dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_FindNearestObject(int, int);
extern int Ov206_AiQueue4OnFlagClear(int);
void Ov206_AiWaitForTarget(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int child = Ov107_FindNearestObject(*(int *)owner, 0);
    *(int *)(owner + 0x10) = child;
    if (child == 0) return;
    *(signed char *)(*(int *)(*(int *)owner + 0x384) + 0xa8) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov206_AiQueue4OnFlagClear);
}
