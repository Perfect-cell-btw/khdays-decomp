/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov084_020b9980;

void Ov084_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov084_020b9980, arg);
}
