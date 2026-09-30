/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv083ZexionClass;

void Ov083_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv083ZexionClass, arg);
}
