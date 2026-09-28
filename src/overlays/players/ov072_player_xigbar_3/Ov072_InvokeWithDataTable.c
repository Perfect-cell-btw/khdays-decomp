/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov072_020ba6d4;

void Ov072_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov072_020ba6d4, arg);
}
