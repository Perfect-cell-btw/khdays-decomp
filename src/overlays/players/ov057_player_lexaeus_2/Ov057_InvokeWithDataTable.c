/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv057LexaeusClass;

void Ov057_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv057LexaeusClass, arg);
}
