/* Instantiates the class this overlay's class descriptor describes (InstantiateClass), passing the
 * argument through. */

extern void InstantiateClass(void *ptr, int arg);
extern int gOv048GoofyClass;

void Ov048_InvokeWithDataTable(int arg) {
    InstantiateClass(&gOv048GoofyClass, arg);
}
