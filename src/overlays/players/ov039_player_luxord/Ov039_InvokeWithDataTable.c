/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov039_020b5554;

void Ov039_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov039_020b5554, arg);
}
