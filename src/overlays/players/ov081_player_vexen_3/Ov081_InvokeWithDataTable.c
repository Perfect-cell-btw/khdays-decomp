/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv081VexenClass;

void Ov081_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv081VexenClass, arg);
}
