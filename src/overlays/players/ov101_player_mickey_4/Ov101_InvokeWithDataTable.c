/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov101_020bc040;

void Ov101_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov101_020bc040, arg);
}
