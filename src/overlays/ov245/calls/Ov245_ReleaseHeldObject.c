/* Ov245_ReleaseHeldObject -- release the held sub-object at +0x3a0, unless the actor's kind byte
 * (+0x1c6) is 1 or there is nothing held. */
extern void TaskList_FinishByTag(int a, int b);

void Ov245_ReleaseHeldObject(int self) {
    if (*(signed char *)(self + 0x1c6) != 1 && *(int *)(self + 0x3a0) != 0) {
        TaskList_FinishByTag(*(int *)(self + 0x3c), *(int *)(self + 0x3a0));
        *(int *)(self + 0x3a0) = 0;
    }
}
