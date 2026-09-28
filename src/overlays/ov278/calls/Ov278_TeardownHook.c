/* Teardown hook: unless the current kind (+0x1c6) is 5, drop the +4 children of +0x3b8 slots 1
 * and 2 (index + 1 folded into the offset) via TaskList_FinishByTag; unless it is 0xb, also drop the first slot's +4 child and release
 * the +0x3c4 handle; then the common release. */
struct Ov236Slot { int pItem; int pChild; };
extern void TaskList_FinishByTag(int a, int b);
extern void Ov107_UnlinkNodeFromOwner();
extern void Ov107_AiState_PostTickBase(int self);

void Ov278_TeardownHook(int self) {
    if (*(signed char *)(self + 0x100 + 0xc6) != 5) {
        signed char i;
        for (i = 0; i < 2; i++) {
            if ((*(struct Ov236Slot **)(self + 0x3b8))[i + 1].pChild != 0) {
                TaskList_FinishByTag(*(int *)(self + 0x3c), (*(struct Ov236Slot **)(self + 0x3b8))[i + 1].pChild);
                (*(struct Ov236Slot **)(self + 0x3b8))[i + 1].pChild = 0;
            }
        }
    }
    if (*(signed char *)(self + 0x100 + 0xc6) != 0xb) {
        if ((*(struct Ov236Slot **)(self + 0x3b8))[0].pChild != 0) {
            TaskList_FinishByTag(*(int *)(self + 0x3c), (*(struct Ov236Slot **)(self + 0x3b8))[0].pChild);
            (*(struct Ov236Slot **)(self + 0x3b8))[0].pChild = 0;
        }
        if (*(int *)(self + 0x3c4) != 0) {
            Ov107_UnlinkNodeFromOwner();
            *(int *)(self + 0x3c4) = 0;
        }
    }
    Ov107_AiState_PostTickBase(self);
}
