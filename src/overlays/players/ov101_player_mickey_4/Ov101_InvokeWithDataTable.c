/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv101MickeyClass;

void Ov101_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv101MickeyClass, arg);
}
