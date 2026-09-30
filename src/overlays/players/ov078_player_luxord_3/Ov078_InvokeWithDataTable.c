/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv078LuxordClass;

void Ov078_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv078LuxordClass, arg);
}
