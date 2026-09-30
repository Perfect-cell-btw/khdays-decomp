/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv053XaldinClass;

void Ov053_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv053XaldinClass, arg);
}
