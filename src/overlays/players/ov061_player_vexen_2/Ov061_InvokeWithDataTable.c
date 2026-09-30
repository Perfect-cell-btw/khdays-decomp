/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv061VexenClass;

void Ov061_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv061VexenClass, arg);
}
