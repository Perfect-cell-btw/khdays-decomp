/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov082_020ba3e0;

void Ov082_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov082_020ba3e0, arg);
}
