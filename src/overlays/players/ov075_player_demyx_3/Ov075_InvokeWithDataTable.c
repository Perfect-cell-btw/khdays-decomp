/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov075_020b9d20;

void Ov075_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov075_020b9d20, arg);
}
