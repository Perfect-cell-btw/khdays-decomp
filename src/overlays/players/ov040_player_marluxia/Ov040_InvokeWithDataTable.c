/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv040MarluxiaClass;

void Ov040_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv040MarluxiaClass, arg);
}
