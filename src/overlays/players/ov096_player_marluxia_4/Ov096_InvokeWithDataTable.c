/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv096MarluxiaClass;

void Ov096_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv096MarluxiaClass, arg);
}
