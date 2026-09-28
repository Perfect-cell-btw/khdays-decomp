/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov038_020b4bd4;

void Ov038_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov038_020b4bd4, arg);
}
