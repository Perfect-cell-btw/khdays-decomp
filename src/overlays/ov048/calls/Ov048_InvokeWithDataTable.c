extern void InstantiateClass(void *ptr, int arg);
extern int data_ov048_020b4ad4;

void Ov048_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov048_020b4ad4, arg);
}
