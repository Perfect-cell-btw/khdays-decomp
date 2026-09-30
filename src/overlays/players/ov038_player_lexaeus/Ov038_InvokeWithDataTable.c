/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv038LexaeusClass;

void Ov038_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv038LexaeusClass, arg);
}
