/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv068RoxasDualClass;

void Ov068_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv068RoxasDualClass, arg);
}
