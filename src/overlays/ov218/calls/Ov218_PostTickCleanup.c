/* Ov218_PostTickCleanup -- release the held sub-object at +0x3e8 (unless the actor's kind byte is 3
 * or nothing is held) and then run the base teardown. Sibling of Ov245_ReleaseHeldObject, which does
 * the same for +0x3a0 and has no base call. */
extern void TaskList_FinishByTag(int a, int b);
extern void Ov107_AiState_PostTickBase(int self);

void Ov218_PostTickCleanup(int self) {
    if (*(signed char *)(self + 0x1c6) != 3 && *(int *)(self + 0x3e8) != 0) {
        TaskList_FinishByTag(*(int *)(self + 0x3c), *(int *)(self + 0x3e8));
        *(int *)(self + 0x3e8) = 0;
    }
    Ov107_AiState_PostTickBase(self);
}
