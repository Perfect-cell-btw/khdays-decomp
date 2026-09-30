/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv090XaldinClass;

void Ov090_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv090XaldinClass, arg);
}
