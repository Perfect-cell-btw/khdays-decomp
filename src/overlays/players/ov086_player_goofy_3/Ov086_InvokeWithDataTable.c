/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv086GoofyClass;

void Ov086_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv086GoofyClass, arg);
}
