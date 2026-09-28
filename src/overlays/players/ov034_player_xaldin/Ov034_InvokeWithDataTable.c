/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov034_020b55c0;

void Ov034_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov034_020b55c0, arg);
}
