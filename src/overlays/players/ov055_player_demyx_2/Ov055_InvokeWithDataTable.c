/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov055_020b7640;

void Ov055_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov055_020b7640, arg);
}
