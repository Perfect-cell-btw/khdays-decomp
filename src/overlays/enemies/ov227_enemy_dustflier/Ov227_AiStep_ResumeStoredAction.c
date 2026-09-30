/* Unless the hw60 gate bit is set, prime the fields and copy the queued state, then dispatch. */
extern int SetIndexedSlot(int, int, void *);
struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
void Ov227_AiStep_ResumeStoredAction(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if ((((struct hw60 *)(*(int *)owner + 0x60))->lo & 1) == 0) return;
    *(signed char *)(owner + 0x74) = 6;
    *(int *)(owner + 0x78) = 0;
    { int obj = *(int *)owner; *(signed char *)(obj + 0x1c7) = *(signed char *)(obj + 0x1c9); }
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
