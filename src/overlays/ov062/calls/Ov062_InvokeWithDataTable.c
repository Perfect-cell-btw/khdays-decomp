/* Ov062_InvokeWithDataTable -- instantiate the ov043 task class, ov062 (twin) (tail-call to
 * InstantiateClass with the class descriptor data_ov062_020b8000). */
extern int InstantiateClass(void *classDesc, int arg);
extern char data_ov062_020b8000[];
int Ov062_InvokeWithDataTable(int arg) {
    return InstantiateClass(data_ov062_020b8000, arg);
}
