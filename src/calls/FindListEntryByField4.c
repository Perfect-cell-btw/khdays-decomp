extern void *List_First();
extern void *List_Next();

void *FindListEntryByField4(int this_, int arg1) {
    void *r = List_First(this_);
    while (r != 0) {
        if (*(int *)((char *)r + 4) == arg1) return r;
        r = List_Next(this_);
    }
    return 0;
}
