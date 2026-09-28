extern int StackAlloc_FreeIfSet();

int StackAlloc_FreeIfSetB(int a) {
    if (a) StackAlloc_FreeIfSet(a);
}
