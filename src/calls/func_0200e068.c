/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to data_02046468. */
extern int data_02046468;

int func_0200e068(void) {
    return data_02046468;
}
