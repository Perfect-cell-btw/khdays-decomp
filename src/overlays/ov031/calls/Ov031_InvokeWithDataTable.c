extern void InstantiateClass(void *ptr, int arg);
extern int data_ov031_020b4cc0;

void Ov031_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov031_020b4cc0, arg);
}
