/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov049_020b4c34;

void Ov049_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov049_020b4c34, arg);
}
