/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv044XionClass;

void Ov044_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv044XionClass, arg);
}
