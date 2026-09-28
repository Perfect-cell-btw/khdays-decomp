/* Walk the +0x4a38 list, invoking Ov025_DestroyEntry on each node (advancing safely first). */
extern void *NNS_FndGetNextListObject(void *list, void *obj);
extern void Ov025_DestroyEntry(int, void *);
void Ov025_DestroyAllListObjects(int param_1) {
    void *node = NNS_FndGetNextListObject((void *)(param_1 + 0x4a38), 0);
    while (node != 0) {
        void *next = NNS_FndGetNextListObject((void *)(param_1 + 0x4a38), node);
        Ov025_DestroyEntry(param_1, node);
        node = next;
    }
}
