/* Sets the mode bit on the slots of every layout entry. */

extern int NNS_FndGetNextListObject();
extern void Ov025_ReleaseTwoSlotsEx_3();

void Ov025_ReleaseAllListSlots(int arg0, unsigned int arg1) {
    int e = NNS_FndGetNextListObject((void *)(arg0 + 19000), 0);
    if (e != 0) {
        do {
            Ov025_ReleaseTwoSlotsEx_3(arg0, e, arg1);
            e = NNS_FndGetNextListObject((void *)(arg0 + 19000), e);
        } while (e != 0);
    }
}
