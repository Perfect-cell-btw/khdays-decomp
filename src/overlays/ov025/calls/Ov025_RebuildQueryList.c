extern int Ov025_DestroyAllListObjects_2();
extern int Ov025_QueryFieldBySelector();

void Ov025_RebuildQueryList(int arg0, int arg1) {
    Ov025_DestroyAllListObjects_2(arg0, arg1);
    Ov025_QueryFieldBySelector(arg0, *(int *)(arg0 + 0xc), arg1);
}
