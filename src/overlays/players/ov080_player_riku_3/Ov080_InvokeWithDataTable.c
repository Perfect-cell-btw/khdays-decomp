/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv080RikuClass;

void Ov080_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv080RikuClass, arg);
}
