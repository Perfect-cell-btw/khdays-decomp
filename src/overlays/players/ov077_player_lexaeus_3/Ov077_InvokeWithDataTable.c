/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov077_020b9ab4;

void Ov077_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov077_020b9ab4, arg);
}
