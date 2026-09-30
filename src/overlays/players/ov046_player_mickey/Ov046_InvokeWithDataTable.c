/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv046MickeyClass;

void Ov046_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv046MickeyClass, arg);
}
