/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv082XionClass;

void Ov082_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv082XionClass, arg);
}
