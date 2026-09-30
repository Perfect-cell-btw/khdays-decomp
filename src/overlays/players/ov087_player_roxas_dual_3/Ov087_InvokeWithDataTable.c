/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv087RoxasDualClass;

void Ov087_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv087RoxasDualClass, arg);
}
