/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv103GoofyClass;

void Ov103_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv103GoofyClass, arg);
}
