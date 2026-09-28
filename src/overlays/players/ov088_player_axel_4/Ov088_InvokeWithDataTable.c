extern void InstantiateClass(void *ptr, int arg);
extern int data_ov088_020bc260;

void Ov088_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov088_020bc260, arg);
}
