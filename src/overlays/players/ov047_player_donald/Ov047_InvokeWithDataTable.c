/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv047DonaldClass;

void Ov047_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv047DonaldClass, arg);
}
