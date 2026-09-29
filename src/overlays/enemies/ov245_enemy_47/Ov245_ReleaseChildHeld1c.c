/* Ov245_ReleaseChildHeld1c -- release the sub-object held by the +0x3a4 child's +0x1c slot (unless
 * the actor's kind byte is 6 or nothing is held) and then run the base teardown. Sibling of
 * Ov245_ReleaseHeldObject / Ov245_ReleaseHeld3a8, which do the same for the actor's own slots. */
extern void TaskList_FinishByTag(int a, int b);
extern void Ov107_AiState_PostTickBase(int self);

void Ov245_ReleaseChildHeld1c(int self) {
    if (*(signed char *)(self + 0x1c6) != 6 && *(int *)(*(int *)(self + 0x3a4) + 0x1c) != 0) {
        TaskList_FinishByTag(*(int *)(self + 0x3c), *(int *)(*(int *)(self + 0x3a4) + 0x1c));
        *(int *)(*(int *)(self + 0x3a4) + 0x1c) = 0;
    }
    Ov107_AiState_PostTickBase(self);
}
