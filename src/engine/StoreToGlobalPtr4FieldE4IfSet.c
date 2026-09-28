/* Stores the value into a field of the object a global points to, when it exists. */

extern int data_0204be08;

void StoreToGlobalPtr4FieldE4IfSet(int arg0) {
    int p = *(int *)((char *)&data_0204be08 + 4);
    if (p != 0) *(int *)(p + 0xe4) = arg0;
}
