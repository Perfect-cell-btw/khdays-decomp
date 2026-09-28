/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov061_020b6f40;

void Ov061_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov061_020b6f40, arg);
}
