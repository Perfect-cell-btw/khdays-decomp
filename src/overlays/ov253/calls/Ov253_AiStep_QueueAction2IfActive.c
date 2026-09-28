/* Unless bit 0 of the hw60 low byte is set, mark state 2 and dispatch via c634. */
extern int SetIndexedSlot(int, int, int);
struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
void Ov253_AiStep_QueueAction2IfActive(int param_1) {
    int obj = *(int *)(*(int *)(param_1 + 4));
    if ((((struct hw60 *)(obj + 0x60))->lo & 1) == 0) return;
    *(signed char *)(obj + 0x1c7) = 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
