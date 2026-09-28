/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov057_020b73d4;

void Ov057_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov057_020b73d4, arg);
}
