/* Calls the hook of every child in the object's child list (+0x88). */

extern void *List_First();
extern void Node_CallHook80(char *node);
extern void *List_Next();

void ProcessListChildren(int this_) {
    void *r = List_First(this_ + 0x88);
    while (r != 0) {
        Node_CallHook80(*(char **)r);
        r = List_Next(this_ + 0x88);
    }
}
