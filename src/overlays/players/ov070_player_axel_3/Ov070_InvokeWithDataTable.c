/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov070_020b9ba0;

void Ov070_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov070_020b9ba0, arg);
}
