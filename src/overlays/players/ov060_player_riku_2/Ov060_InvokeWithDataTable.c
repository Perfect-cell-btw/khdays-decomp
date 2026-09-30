/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv060RikuClass;

void Ov060_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv060RikuClass, arg);
}
