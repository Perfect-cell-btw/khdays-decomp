/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov078_020ba434;

void Ov078_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov078_020ba434, arg);
}
