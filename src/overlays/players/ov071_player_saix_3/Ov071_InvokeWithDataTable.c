/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv071SaixClass;

void Ov071_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv071SaixClass, arg);
}
