/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv067GoofyClass;

void Ov067_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv067GoofyClass, arg);
}
