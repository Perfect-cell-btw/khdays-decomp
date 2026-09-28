extern int OSi_FreeStackAlloc();

int StackAlloc_FreeIfSet(int a) {
    if (a) return OSi_FreeStackAlloc(a);
}
