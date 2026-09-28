/* Unless the parent's +0x454 is busy, drain +0x3ec by the frame delta; once it hits 0 with +0x3d0
 * clear and 020d26c8 accepting, store the 020d26e0 result into +0x20 and dispatch. */
extern int Ov253_QueueActor_IsFull(int);
extern int Ov253_QueuePush(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_QueueActor_AiWaitEntry(int);
void Ov253_QueueActor_AiWaitTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int obj = *(int *)owner;
    if (*(int *)(*(int *)(obj + 0x388) + 0x454) != 0) return;
    *(int *)(obj + 0x3ec) = *(int *)(obj + 0x3ec) - *(int *)(*(int *)param_1 + 0x2c);
    if (*(int *)(*(int *)owner + 0x3ec) > 0) return;
    if (*(int *)(*(int *)owner + 0x3d0) != 0) return;
    if (Ov253_QueueActor_IsFull(*(int *)owner) != 0) return;
    *(unsigned short *)(owner + 0x20) = Ov253_QueuePush(*(int *)owner, 2, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_QueueActor_AiWaitEntry);
}
