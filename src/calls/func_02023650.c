/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to data_0204c028. */
extern int data_0204c028;

int func_02023650(void) {
    return data_0204c028;
}
