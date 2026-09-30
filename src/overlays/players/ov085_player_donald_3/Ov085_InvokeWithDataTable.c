/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv085DonaldClass;

void Ov085_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv085DonaldClass, arg);
}
