/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov096_020bc014;

void Ov096_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov096_020bc014, arg);
}
