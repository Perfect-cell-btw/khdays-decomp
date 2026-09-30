/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv039LuxordClass;

void Ov039_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv039LuxordClass, arg);
}
