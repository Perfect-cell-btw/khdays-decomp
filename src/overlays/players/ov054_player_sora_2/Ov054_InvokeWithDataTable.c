/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv054SoraClass;

void Ov054_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv054SoraClass, arg);
}
