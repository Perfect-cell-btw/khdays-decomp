/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to data_ov009_020563ec. */
extern int data_ov009_020563ec;

int func_ov009_0204ee00(void) {
    return data_ov009_020563ec;
}
