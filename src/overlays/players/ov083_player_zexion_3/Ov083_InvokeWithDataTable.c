/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov083_020b9a60;

void Ov083_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov083_020b9a60, arg);
}
