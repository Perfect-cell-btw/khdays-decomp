/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int data_ov081_020b9620;

void Ov081_InvokeWithDataTable(int arg) {
    InstantiateClass(&data_ov081_020b9620, arg);
}
