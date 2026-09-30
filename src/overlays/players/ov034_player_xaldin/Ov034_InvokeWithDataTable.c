/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv034XaldinClass;

void Ov034_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv034XaldinClass, arg);
}
