/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv079MarluxiaClass;

void Ov079_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv079MarluxiaClass, arg);
}
