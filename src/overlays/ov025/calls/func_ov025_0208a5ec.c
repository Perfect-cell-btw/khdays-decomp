/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov025_MergeSortList. */
extern void *Ov025_MergeSortList();

void *func_ov025_0208a5ec() {
    return Ov025_MergeSortList();
}
