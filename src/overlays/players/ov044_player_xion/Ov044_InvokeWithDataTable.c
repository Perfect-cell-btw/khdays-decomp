/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov044_020b5500;

void Ov044_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov044_020b5500, arg);
}
