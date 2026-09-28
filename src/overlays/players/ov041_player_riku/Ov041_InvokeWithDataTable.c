/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov041_020b4c60;

void Ov041_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov041_020b4c60, arg);
}
