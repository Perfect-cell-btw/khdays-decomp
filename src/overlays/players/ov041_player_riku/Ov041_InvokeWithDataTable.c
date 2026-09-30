/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv041RikuClass;

void Ov041_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv041RikuClass, arg);
}
