/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov036_020b4e40;

void Ov036_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov036_020b4e40, arg);
}
