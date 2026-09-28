extern void InstantiateClass(void *ptr, int arg);
extern int data_ov060_020b7460;

void Ov060_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov060_020b7460, arg);
}
