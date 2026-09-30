/* Lazily allocates the 0x40-byte record held at gLangPath+4 out of the heap in
 * data_0204c024, then records `n` in the halfword at gLangPath+0. */
extern int gLangPath[];
extern void *data_0204c024;
extern void *AllocFromExpHeapWrapper(int size, void *heap);

void Record_EnsureAllocatedAndSetId(int n) {
    if (gLangPath[1] == 0) {
        gLangPath[1] = (int)AllocFromExpHeapWrapper(0x40, data_0204c024);
    }
    *(short *)gLangPath = (short)n;
}
