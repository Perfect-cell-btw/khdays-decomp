/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv052XigbarClass;

void Ov052_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv052XigbarClass, arg);
}
