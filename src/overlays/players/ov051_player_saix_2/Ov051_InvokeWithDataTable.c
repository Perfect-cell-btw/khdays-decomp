/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv051SaixClass;

void Ov051_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv051SaixClass, arg);
}
