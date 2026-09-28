/* Searches the doubly-linked list at this (List_First first / List_Next next) for an entry whose +4
 * field equals arg1; returns that entry or 0. */

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
