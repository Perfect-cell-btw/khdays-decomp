extern int Archive_LoadFile();
extern void Ov025_InstantiateAndLinkElements();
extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_LoadBlockProcessAndFree(int *arg0, char *arg1, int arg2, int arg3) {
    int *p = (int *)Archive_LoadFile(arg1, 0xe, arg2, arg3);
    Ov025_InstantiateAndLinkElements(arg0, p, arg2);
    if (p != (int *)0) NNSi_FndFreeFromDefaultHeap(p);
}
