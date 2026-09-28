/* Walk the +0x4a38 list, invoking 02055544 on each node. */
extern void *NNS_FndGetNextListObject(void *list, void *obj);
extern void Ov008_FillAnchorPair(int self, int node);
void Ov008_ProcessAllListNodes(int param_1) {
    void *node = NNS_FndGetNextListObject((void *)(param_1 + 0x4a38), 0);
    while (node != 0) {
        Ov008_FillAnchorPair(param_1, (int)node);
        node = NNS_FndGetNextListObject((void *)(param_1 + 0x4a38), node);
    }
}
