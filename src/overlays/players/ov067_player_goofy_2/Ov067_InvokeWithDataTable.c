/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov067_020b72d4;

void Ov067_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov067_020b72d4, arg);
}
