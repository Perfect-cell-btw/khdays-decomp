struct v3 { int a, b, c; };
extern void NNSi_FndDestroyDoubleList(void *p);
extern void List_Init(void *p);
extern void *List_InsertSorted(int a, int b, int c);
void Ov287_LoadWaypoints(int obj, int size, int *entries) {
    struct v3 *src;
    int count, i;
    *(int *)(obj + 0x390) = entries[0];
    src = (struct v3 *)(entries + 1);
    NNSi_FndDestroyDoubleList((void *)(obj + 0x398));
    List_Init((void *)(obj + 0x398));
    count = (int)((unsigned int)(size - 4) / 12);
    for (i = 0; i < count; i++) {
        struct v3 *slot = (struct v3 *)List_InsertSorted(obj + 0x398, 0xc, 0x64);
        *slot = *src;
        src++;
    }
}
