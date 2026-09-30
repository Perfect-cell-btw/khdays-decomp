/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv033SaixClass;

void Ov033_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv033SaixClass, arg);
}
