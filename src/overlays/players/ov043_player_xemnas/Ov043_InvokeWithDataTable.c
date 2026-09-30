/* Ov043_InvokeWithDataTable -- instantiate the ov043 task class, ov043 (tail-call to
 * InstantiateClass with the class descriptor gOv043XemnasClass). */
extern int InstantiateClass(void *classDesc, int arg);
extern char gOv043XemnasClass[];
int Ov043_InvokeWithDataTable(int arg) {
    return InstantiateClass(gOv043XemnasClass, arg);
}
