extern void *CallocInstance(int size);
extern void List_Init(void *p);

void *ObjList_New(void) {
    int *p = (int *)CallocInstance(0x30);
    p[10] = 0;
    List_Init(p);
    return p;
}
