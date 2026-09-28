/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov080_020b9b40;

void Ov080_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov080_020b9b40, arg);
}
