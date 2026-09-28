/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov076_020b9c74;

void Ov076_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov076_020b9c74, arg);
}
