/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to data_0204ad4c. */
extern int data_0204ad4c;

int func_0201b3d8(void) {
    return data_0204ad4c;
}
