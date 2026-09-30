/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv073XaldinClass;

void Ov073_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv073XaldinClass, arg);
}
