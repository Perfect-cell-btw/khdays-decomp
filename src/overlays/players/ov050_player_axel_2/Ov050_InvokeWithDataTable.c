/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov050_020b74c0;

void Ov050_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov050_020b74c0, arg);
}
