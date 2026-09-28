/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov035_020b4bf4;

void Ov035_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov035_020b4bf4, arg);
}
