/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv036DemyxClass;

void Ov036_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv036DemyxClass, arg);
}
