/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov037_020b4d94;

void Ov037_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov037_020b4d94, arg);
}
