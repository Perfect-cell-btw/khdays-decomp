/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv084MickeyClass;

void Ov084_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv084MickeyClass, arg);
}
