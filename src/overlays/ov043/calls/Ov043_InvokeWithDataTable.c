/* Ov043_InvokeWithDataTable -- instantiate the ov043 task class, ov043 (tail-call to
 * InstantiateClass with the class descriptor data_ov043_020b5800). */
extern int InstantiateClass(void *classDesc, int arg);
extern char data_ov043_020b5800[];
int Ov043_InvokeWithDataTable(int arg) {
    return InstantiateClass(data_ov043_020b5800, arg);
}
