/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv065MickeyClass;

void Ov065_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv065MickeyClass, arg);
}
