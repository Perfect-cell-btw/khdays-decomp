/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov099_020bcaa0;

void Ov099_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov099_020bcaa0, arg);
}
