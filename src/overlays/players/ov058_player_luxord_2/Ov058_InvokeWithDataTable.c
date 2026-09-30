/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv058LuxordClass;

void Ov058_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv058LuxordClass, arg);
}
