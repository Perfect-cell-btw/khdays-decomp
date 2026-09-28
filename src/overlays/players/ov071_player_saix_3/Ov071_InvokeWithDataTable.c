/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov071_020b99e0;

void Ov071_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov071_020b99e0, arg);
}
