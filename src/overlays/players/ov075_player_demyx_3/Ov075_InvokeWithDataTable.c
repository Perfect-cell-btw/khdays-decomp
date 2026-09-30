/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv075DemyxClass;

void Ov075_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv075DemyxClass, arg);
}
