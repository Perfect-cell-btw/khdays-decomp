/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to data_027e0088. */
extern int data_027e0088;

int func_01ff80a8(void) {
    return data_027e0088;
}
