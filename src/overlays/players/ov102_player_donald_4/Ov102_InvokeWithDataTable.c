/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv102DonaldClass;

void Ov102_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv102DonaldClass, arg);
}
