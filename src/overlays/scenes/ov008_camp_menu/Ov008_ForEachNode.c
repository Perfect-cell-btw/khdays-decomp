/* Ov008_ForEachNode -- apply Ov008_RemoveAndFreeItem to every node in the object list at
 * param_1+0x1cc (fetching the next link before the callback, so callbacks may unlink). */
extern int  NNS_FndGetNextListObject(void *list, int obj);
extern void Ov008_RemoveAndFreeItem(int owner, int node);

void Ov008_ForEachNode(int param_1) {
    int node = NNS_FndGetNextListObject((void *)(param_1 + 0x1cc), 0);
    int next;
    if (node == 0) {
        return;
    }
    do {
        next = NNS_FndGetNextListObject((void *)(param_1 + 0x1cc), node);
        Ov008_RemoveAndFreeItem(param_1, node);
        node = next;
    } while (next != 0);
}
