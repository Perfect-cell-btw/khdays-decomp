/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov089_020bc0a0;

void Ov089_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov089_020bc0a0, arg);
}
