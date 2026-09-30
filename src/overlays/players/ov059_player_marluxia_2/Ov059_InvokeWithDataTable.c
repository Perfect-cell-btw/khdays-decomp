/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv059MarluxiaClass;

void Ov059_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv059MarluxiaClass, arg);
}
