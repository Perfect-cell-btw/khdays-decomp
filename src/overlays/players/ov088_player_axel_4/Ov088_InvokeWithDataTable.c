/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv088AxelClass;

void Ov088_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv088AxelClass, arg);
}
