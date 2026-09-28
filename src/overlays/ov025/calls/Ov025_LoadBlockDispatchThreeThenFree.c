extern int Archive_LoadFile();
extern void Ov025_LoadLayoutResources();
extern void Ov025_LoadElemsFromLayout();
extern void Ov025_BuildLayoutFromTagTable();
extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_LoadBlockDispatchThreeThenFree(int arg0, char *arg1, int arg2, int arg3) {
    int *p = (int *)Archive_LoadFile(arg1, 0xe, arg2, arg3);
    int b = p[2];
    int a = p[1];
    Ov025_LoadLayoutResources(arg0, (int)p + *p);
    Ov025_LoadElemsFromLayout(arg0, (int)p + a);
    Ov025_BuildLayoutFromTagTable(arg0, (int)p + b);
    if (p != (int *)0) NNSi_FndFreeFromDefaultHeap(p);
}
