/* Ov062_InvokeWithDataTable -- instantiate the ov043 task class, ov062 (twin) (tail-call to
 * InstantiateClass with the class descriptor gOv062XemnasClass). */
extern int InstantiateClass(void *classDesc, int arg);
extern char gOv062XemnasClass[];
int Ov062_InvokeWithDataTable(int arg) {
    return InstantiateClass(gOv062XemnasClass, arg);
}
