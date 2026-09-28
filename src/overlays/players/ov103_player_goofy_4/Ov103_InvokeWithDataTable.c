/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov103_020bc074;

void Ov103_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov103_020bc074, arg);
}
