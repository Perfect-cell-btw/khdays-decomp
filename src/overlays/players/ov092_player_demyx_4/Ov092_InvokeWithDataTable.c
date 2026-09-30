/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv092DemyxClass;

void Ov092_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv092DemyxClass, arg);
}
