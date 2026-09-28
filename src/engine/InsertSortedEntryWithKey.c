extern void *CallocInstance();
extern void List_Init();
extern void *List_InsertSorted();
extern int FindResourceIndexByName();
short *InsertSortedEntryWithKey(int param_1, short param_2, unsigned short *param_3)
{
    short *e;
    if (*(int *)(param_1 + 0x90) == 0) {
        void *p = CallocInstance(0x28);
        *(void **)(param_1 + 0x90) = p;
        List_Init(p);
    }
    e = (short *)List_InsertSorted(*(int *)(param_1 + 0x90), 0x30, 100);
    *e = param_2;
    e[1] = (short)FindResourceIndexByName(param_1, param_3);
    return e;
}
