/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov063_020b7d00;

void Ov063_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov063_020b7d00, arg);
}
