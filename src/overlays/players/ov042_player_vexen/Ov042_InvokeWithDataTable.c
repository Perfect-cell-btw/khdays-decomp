/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv042VexenClass;

void Ov042_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv042VexenClass, arg);
}
