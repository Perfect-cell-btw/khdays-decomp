/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv072XigbarClass;

void Ov072_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv072XigbarClass, arg);
}
