/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_MergeSortList. */
extern void *Ov008_MergeSortList();

void *func_ov008_0205697c() {
    return Ov008_MergeSortList();
}
