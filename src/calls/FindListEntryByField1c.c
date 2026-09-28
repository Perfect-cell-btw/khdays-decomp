extern void *List_First();
extern void *List_Next();

void *FindListEntryByField1c(int this_, int arg1) {
    void *r;
    if (arg1 == 0) return 0;
    r = List_First(this_);
    while (r != 0) {
        if (*(int *)((char *)r + 0x1c) == arg1) return r;
        r = List_Next(this_);
    }
    return 0;
}
