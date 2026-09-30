/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv070AxelClass;

void Ov070_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv070AxelClass, arg);
}
