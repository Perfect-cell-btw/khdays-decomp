/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv050AxelClass;

void Ov050_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv050AxelClass, arg);
}
