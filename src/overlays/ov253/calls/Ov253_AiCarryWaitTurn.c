/* Feed the linked emitter node, then only when the retimed 020d2824 count matches +0x28 clear
 * +0x1c and dispatch 020d0674. */
extern int Actor_SetVecAndSyncChild(int, int);
extern int Ov253_QueueActor_CurrentKey(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_CarryTick(int);
void Ov253_AiCarryWaitTurn(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int obj = *(int *)owner;
    int a = *(int *)(obj + 0x3bc);
    int b = *(int *)(obj + 0x384);
    int p = *(int *)(a + 0x18c);
    int save = *(int *)(b + 0x460);
    Actor_SetVecAndSyncChild(*(int *)(p + 0x20), *(int *)(b + 0x394) + 0x14);
    if (*(short *)(owner + 0x28) != Ov253_QueueActor_CurrentKey(save)) return;
    *(int *)(owner + 0x1c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_CarryTick);
}
