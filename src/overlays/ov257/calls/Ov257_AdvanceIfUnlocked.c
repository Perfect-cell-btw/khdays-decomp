extern void Task_MarkFinished(int self);
/* Advance the slot only while the first sub-object is unlocked (+0xaf of subobjects[0]). */
void Ov257_AdvanceIfUnlocked(int self) {
    if (*(unsigned char *)(*(int *)(*(int *)(*(int *)(self + 4)) + 0x3a4) + 0xaf) != 0) {
        return;
    }
    Task_MarkFinished(self);
}
