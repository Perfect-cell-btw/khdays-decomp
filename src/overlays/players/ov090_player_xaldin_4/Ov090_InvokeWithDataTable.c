/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov090_020bcb60;

void Ov090_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov090_020bcb60, arg);
}
