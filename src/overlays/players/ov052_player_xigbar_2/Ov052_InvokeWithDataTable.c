/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov052_020b7ff4;

void Ov052_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov052_020b7ff4, arg);
}
