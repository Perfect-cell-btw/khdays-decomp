/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv091SoraClass;

void Ov091_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv091SoraClass, arg);
}
