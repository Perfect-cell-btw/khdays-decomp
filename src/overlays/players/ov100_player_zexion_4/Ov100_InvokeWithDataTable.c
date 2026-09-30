/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv100ZexionClass;

void Ov100_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv100ZexionClass, arg);
}
