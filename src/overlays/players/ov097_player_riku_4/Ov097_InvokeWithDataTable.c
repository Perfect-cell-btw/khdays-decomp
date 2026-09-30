/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv097RikuClass;

void Ov097_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv097RikuClass, arg);
}
