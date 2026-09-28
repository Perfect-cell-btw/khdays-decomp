/* Unless the hw60 gate bit is set, wire the sub-block pointers, spawn via 020c5c54, mark state 1. */
extern int SetIndexedSlot(int, int, void *);
struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
extern int Ov107_MoveNodeAndRelayout(int, int);
void Ov255_Partner_AiWaitActive(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if ((((struct hw60 *)(*(int *)owner + 0x60))->lo & 1) == 0) return;
    *(int *)(owner + 0x20) = *(int *)owner + 0x3a8;
    *(int *)(owner + 0x24) = *(int *)owner + 0x3b8;
    Ov107_MoveNodeAndRelayout(*(int *)owner, *(int *)owner + 0x390);
    *(signed char *)(*(int *)owner + 0x1c7) = 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
