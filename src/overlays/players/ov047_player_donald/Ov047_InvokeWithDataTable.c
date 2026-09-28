/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov047_020b42f4;

void Ov047_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov047_020b42f4, arg);
}
