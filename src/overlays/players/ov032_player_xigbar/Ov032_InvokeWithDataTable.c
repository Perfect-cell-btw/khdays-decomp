/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov032_020b57f4;

void Ov032_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov032_020b57f4, arg);
}
