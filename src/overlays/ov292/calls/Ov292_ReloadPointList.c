struct v3 { int a, b, c; };
extern void NNSi_FndDestroyDoubleList(void *p);
extern void List_Init(void *p);
extern void *List_InsertSorted(int a, int b, int c);
void Ov292_ReloadPointList(int obj, int size, int *entries) {
    struct v3 *src;
    int i;
    src = (struct v3 *)entries;
    NNSi_FndDestroyDoubleList((void *)(obj + 0x394));
    List_Init((void *)(obj + 0x394));
    size = (int)((unsigned int)size / 12);
    for (i = 0; i < size; i++) {
        struct v3 *slot = (struct v3 *)List_InsertSorted(obj + 0x394, 0xc, 0x64);
        *slot = *src;
        src++;
    }
}
