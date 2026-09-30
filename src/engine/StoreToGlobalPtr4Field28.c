/* Stores the value into a field of the context object a global points to. */

extern int gObjSystem;

void StoreToGlobalPtr4Field28(int arg0) {
    *(int *)(*(int *)((char *)&gObjSystem + 4) + 0x28) = arg0;
}
