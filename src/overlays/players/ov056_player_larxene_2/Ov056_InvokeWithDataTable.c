/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov056_020b7594;

void Ov056_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov056_020b7594, arg);
}
