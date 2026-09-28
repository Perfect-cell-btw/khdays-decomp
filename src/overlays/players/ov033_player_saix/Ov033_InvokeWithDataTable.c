/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov033_020b4b00;

void Ov033_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov033_020b4b00, arg);
}
