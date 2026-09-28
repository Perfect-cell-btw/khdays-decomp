/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov093_020bc334;

void Ov093_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov093_020bc334, arg);
}
