/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv045ZexionClass;

void Ov045_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv045ZexionClass, arg);
}
