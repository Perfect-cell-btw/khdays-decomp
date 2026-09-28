/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov045_020b4b80;

void Ov045_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov045_020b4b80, arg);
}
