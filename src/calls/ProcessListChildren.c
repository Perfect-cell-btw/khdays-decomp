extern void *List_First();
extern void Node_CallHook80();
extern void *List_Next();

void ProcessListChildren(int this_) {
    void *r = List_First(this_ + 0x88);
    while (r != 0) {
        Node_CallHook80(*(int *)r);
        r = List_Next(this_ + 0x88);
    }
}
