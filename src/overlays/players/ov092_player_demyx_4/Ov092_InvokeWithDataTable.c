/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov092_020bc3e0;

void Ov092_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov092_020bc3e0, arg);
}
