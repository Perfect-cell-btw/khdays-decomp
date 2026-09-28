/* Removes a node from the field context's list (+0xa4) and frees it. */

extern int NNS_FndRemoveListObject();
extern void NNSi_FndFreeFromDefaultHeap();
extern int data_ov002_0207f60c;

void Ov002_RemoveAndFreeNode(int arg0) {
    NNS_FndRemoveListObject(*(int *)&data_ov002_0207f60c + 0xa4, arg0);
    if (arg0 == 0) {
        return;
    }
    NNSi_FndFreeFromDefaultHeap(arg0);
}
