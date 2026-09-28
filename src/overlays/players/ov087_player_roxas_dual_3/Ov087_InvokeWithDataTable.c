/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov087_020b9b14;

void Ov087_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov087_020b9b14, arg);
}
