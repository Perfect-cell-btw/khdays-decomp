/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov058_020b7d54;

void Ov058_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov058_020b7d54, arg);
}
