/* Unless the predicate holds for the +0x20 value, dispatch via c634. */
extern int Ov253_FindEntryByKey(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_QueueActor_AiWaitTick(int);
void Ov253_QueueActor_AiWaitEntry(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov253_FindEntryByKey(*(int *)owner, *(short *)(owner + 0x20)) != 0) return;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_QueueActor_AiWaitTick);
}
