/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv099XionClass;

void Ov099_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv099XionClass, arg);
}
