/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov064_020b7380;

void Ov064_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov064_020b7380, arg);
}
