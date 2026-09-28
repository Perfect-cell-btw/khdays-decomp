extern void *List_First(void *listHead);
extern void *List_Next(void *listHead);
extern int Ov107_HitShape_TestSegment(void *criteria, void *query, int flags);

int Ov107_CollectSegmentOverlaps(char *owner, void *query, void **results) {
    char *sub = *(char **)(owner + 4);
    int count = 0;
    char *listHead = sub + 0xa8;
    void *iter;
    void **node;

    iter = List_First(listHead);
    node = (iter == 0) ? 0 : *(void ***)iter;

    while (node != 0) {
        if (node[1] == *(void **)(owner + 4)) {
            void *criteria = *(void **)((char *)node + 0x1d8);
            if (Ov107_HitShape_TestSegment(criteria, query, 0) != 0) {
                results[count] = node;
                count++;
            }
        }
        iter = List_Next(listHead);
        node = (iter == 0) ? 0 : *(void ***)iter;
    }
    return count;
}
