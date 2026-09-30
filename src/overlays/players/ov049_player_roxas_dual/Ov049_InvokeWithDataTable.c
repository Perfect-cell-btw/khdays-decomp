/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv049RoxasDualClass;

void Ov049_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv049RoxasDualClass, arg);
}
