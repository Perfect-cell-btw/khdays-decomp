/* Creates the overlay's class instance with the argument. */

extern void *InstantiateClass();
extern int gOv098VexenClass;

void *Ov098_InvokeWithDataTable(int this_) {
    return InstantiateClass(&gOv098VexenClass, this_);
}
