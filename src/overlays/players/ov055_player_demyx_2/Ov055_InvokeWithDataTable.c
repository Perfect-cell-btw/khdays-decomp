/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv055DemyxClass;

void Ov055_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv055DemyxClass, arg);
}
