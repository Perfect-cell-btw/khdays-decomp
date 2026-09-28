/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov079_020b9954;

void Ov079_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov079_020b9954, arg);
}
