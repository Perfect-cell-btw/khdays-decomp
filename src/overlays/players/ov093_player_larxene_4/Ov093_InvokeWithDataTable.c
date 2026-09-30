/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv093LarxeneClass;

void Ov093_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv093LarxeneClass, arg);
}
