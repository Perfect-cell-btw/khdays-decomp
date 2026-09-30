/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv104RoxasDualClass;

void Ov104_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv104RoxasDualClass, arg);
}
