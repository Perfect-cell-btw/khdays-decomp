/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv066DonaldClass;

void Ov066_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv066DonaldClass, arg);
}
