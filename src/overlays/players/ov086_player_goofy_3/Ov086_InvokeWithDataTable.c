/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov086_020b99b4;

void Ov086_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov086_020b99b4, arg);
}
