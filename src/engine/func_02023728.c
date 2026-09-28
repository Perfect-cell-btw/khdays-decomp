extern int NNS_FndFreeToExpHeap();
extern int data_0204c028;

int func_02023728(int arg0, int *heap) {
    if (heap == 0) heap = *(int **)&data_0204c028;
    return NNS_FndFreeToExpHeap(*heap, arg0);
}
