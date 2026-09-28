/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov066_020b6af4;

void Ov066_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov066_020b6af4, arg);
}
