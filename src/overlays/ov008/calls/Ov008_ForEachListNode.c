/* Ov008_ForEachListNode -- apply Ov008_ReleaseTwoSlotsEx_2(.,.,param_2) to every node in the object list
 * at param_1+0x4a38. */
extern int  NNS_FndGetNextListObject(void *list, int obj);
extern void Ov008_ReleaseTwoSlotsEx_2(int owner, int node, unsigned int arg);

void Ov008_ForEachListNode(int param_1, unsigned int param_2) {
    int node = NNS_FndGetNextListObject((void *)(param_1 + 0x4a38), 0);
    if (node != 0) {
        do {
            Ov008_ReleaseTwoSlotsEx_2(param_1, node, param_2);
            node = NNS_FndGetNextListObject((void *)(param_1 + 0x4a38), node);
        } while (node != 0);
    }
}
