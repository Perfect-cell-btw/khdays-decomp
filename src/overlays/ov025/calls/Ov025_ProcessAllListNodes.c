/* Walk the +0x4a38 list, invoking Ov025_FillAnchorPair on each node. */

extern int NNS_FndGetNextListObject();
extern void Ov025_FillAnchorPair();

void Ov025_ProcessAllListNodes(int arg0) {
    int e = NNS_FndGetNextListObject((void *)(arg0 + 19000), 0);
    if (e != 0) {
        do {
            Ov025_FillAnchorPair(arg0, e);
            e = NNS_FndGetNextListObject((void *)(arg0 + 19000), e);
        } while (e != 0);
    }
}
