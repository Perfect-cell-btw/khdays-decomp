/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv077LexaeusClass;

void Ov077_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv077LexaeusClass, arg);
}
