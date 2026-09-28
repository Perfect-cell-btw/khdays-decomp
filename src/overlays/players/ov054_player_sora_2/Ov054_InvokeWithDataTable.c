/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov054_020b73f4;

void Ov054_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov054_020b73f4, arg);
}
