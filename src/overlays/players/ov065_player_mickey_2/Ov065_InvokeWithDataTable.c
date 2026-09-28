/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov065_020b72a0;

void Ov065_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov065_020b72a0, arg);
}
