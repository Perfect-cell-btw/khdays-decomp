/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov094_020bc174;

void Ov094_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov094_020bc174, arg);
}
