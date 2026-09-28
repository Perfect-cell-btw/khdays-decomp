/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov095_020bcaf4;

void Ov095_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov095_020bcaf4, arg);
}
