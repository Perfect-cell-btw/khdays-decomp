/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv035SoraClass;

void Ov035_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv035SoraClass, arg);
}
