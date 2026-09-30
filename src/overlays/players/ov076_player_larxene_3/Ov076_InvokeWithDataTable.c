/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv076LarxeneClass;

void Ov076_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv076LarxeneClass, arg);
}
