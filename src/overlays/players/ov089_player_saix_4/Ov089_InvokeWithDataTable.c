/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv089SaixClass;

void Ov089_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv089SaixClass, arg);
}
