/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv032XigbarClass;

void Ov032_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv032XigbarClass, arg);
}
