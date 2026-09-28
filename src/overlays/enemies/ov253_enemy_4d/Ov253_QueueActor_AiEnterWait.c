/* Kick anim (0, phase 1), latch +0x3ec, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_QueueActor_AiWaitTick(int);
void Ov253_QueueActor_AiEnterWait(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 0, 1);
    *(int *)(*(int *)owner + 0x3ec) = 0x1e000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_QueueActor_AiWaitTick);
}
