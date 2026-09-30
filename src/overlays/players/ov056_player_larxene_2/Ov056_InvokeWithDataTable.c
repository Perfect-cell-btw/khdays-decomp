/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv056LarxeneClass;

void Ov056_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv056LarxeneClass, arg);
}
