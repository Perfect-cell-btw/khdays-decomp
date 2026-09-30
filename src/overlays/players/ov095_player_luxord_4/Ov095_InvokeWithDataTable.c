/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv095LuxordClass;

void Ov095_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv095LuxordClass, arg);
}
