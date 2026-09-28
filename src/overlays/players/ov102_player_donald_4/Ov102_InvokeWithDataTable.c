/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov102_020bb894;

void Ov102_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov102_020bb894, arg);
}
