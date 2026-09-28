/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov046_020b4aa0;

void Ov046_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov046_020b4aa0, arg);
}
