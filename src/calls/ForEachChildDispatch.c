extern void *List_First();
extern void DispatchObjectCallbacks();
extern void *List_Next();

void ForEachChildDispatch(int this_, int arg1) {
    void *r = List_First(this_ + 0x88);
    while (r != 0) {
        DispatchObjectCallbacks(*(int *)r, arg1);
        r = List_Next(this_ + 0x88);
    }
}
