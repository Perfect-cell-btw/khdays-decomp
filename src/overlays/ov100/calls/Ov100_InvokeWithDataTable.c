extern void InstantiateClass(void *ptr, int arg);
extern int data_ov100_020bc120;

void Ov100_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov100_020bc120, arg);
}
