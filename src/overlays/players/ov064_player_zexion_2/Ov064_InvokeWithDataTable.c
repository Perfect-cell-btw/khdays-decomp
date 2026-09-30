/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv064ZexionClass;

void Ov064_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv064ZexionClass, arg);
}
