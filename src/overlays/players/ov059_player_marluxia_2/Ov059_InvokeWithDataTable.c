/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov059_020b7274;

void Ov059_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov059_020b7274, arg);
}
