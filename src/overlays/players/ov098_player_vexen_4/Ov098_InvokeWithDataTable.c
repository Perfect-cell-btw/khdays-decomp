/* Creates the overlay's class instance with the argument. */

extern void *InstantiateClass();
extern int data_ov098_020bbce0;

void *Ov098_InvokeWithDataTable(int this_) {
    return InstantiateClass(&data_ov098_020bbce0, this_);
}
