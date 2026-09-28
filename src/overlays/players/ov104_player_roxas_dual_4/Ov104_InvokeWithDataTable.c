/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov104_020bc1d4;

void Ov104_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov104_020bc1d4, arg);
}
