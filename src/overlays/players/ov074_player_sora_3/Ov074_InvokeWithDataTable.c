/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv074SoraClass;

void Ov074_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv074SoraClass, arg);
}
