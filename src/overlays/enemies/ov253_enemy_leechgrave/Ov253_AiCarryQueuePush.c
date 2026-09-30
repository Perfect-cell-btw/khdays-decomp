/* Feed the linked emitter node; if 020d26c8 rejects, bail, otherwise store the 020d26e0 result
 * into +0x28 and dispatch 020d0610. */
extern int Actor_SetVecAndSyncChild(int, int);
extern int Ov253_QueueActor_IsFull(int);
extern int Ov253_QueuePush(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_AiCarryWaitTurn(int);
void Ov253_AiCarryQueuePush(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int obj = *(int *)owner;
    int a = *(int *)(obj + 0x3bc);
    int b = *(int *)(obj + 0x384);
    int p = *(int *)(a + 0x18c);
    int save = *(int *)(b + 0x460);
    Actor_SetVecAndSyncChild(*(int *)(p + 0x20), *(int *)(b + 0x394) + 0x14);
    if (Ov253_QueueActor_IsFull(save) != 0) return;
    *(unsigned short *)(owner + 0x28) = Ov253_QueuePush(save, 0, *(int *)(*(int *)owner + 0x3bc));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AiCarryWaitTurn);
}
