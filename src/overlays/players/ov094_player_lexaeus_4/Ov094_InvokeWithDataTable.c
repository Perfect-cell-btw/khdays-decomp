/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv094LexaeusClass;

void Ov094_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv094LexaeusClass, arg);
}
