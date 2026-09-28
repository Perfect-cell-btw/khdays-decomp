extern void InstantiateClass(void *ptr, int arg);
extern int data_ov040_020b4a74;

void Ov040_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov040_020b4a74, arg);
}
