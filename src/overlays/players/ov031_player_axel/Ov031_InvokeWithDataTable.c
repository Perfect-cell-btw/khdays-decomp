/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv031AxelClass;

void Ov031_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv031AxelClass, arg);
}
