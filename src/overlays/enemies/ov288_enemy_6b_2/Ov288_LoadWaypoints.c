/* Stores the waypoint count and rebuilds the sorted waypoint list from the 12-byte entries. */

struct ent { int w[3]; };
extern void NNSi_FndDestroyDoubleList(void *p);
extern void List_Init(void *p);
extern void *List_InsertSorted(int a, int b, int c);
void Ov288_LoadWaypoints(int obj, int size, int *entries) {
    struct ent *src;
    int count, i;
    *(int *)(obj + 0x390) = entries[0];
    src = (struct ent *)((char *)entries + 4);
    NNSi_FndDestroyDoubleList((void *)(obj + 0x398));
    List_Init((void *)(obj + 0x398));
    count = (int)((unsigned int)(size - 4) / 12);
    for (i = 0; i < count; i++) {
        struct ent *slot = (struct ent *)List_InsertSorted(obj + 0x398, 12, 0x64);
        *slot = *src;
        src++;
    }
}
