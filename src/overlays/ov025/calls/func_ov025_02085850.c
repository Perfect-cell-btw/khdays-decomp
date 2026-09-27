/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to data_ov025_020b574c. */
extern int data_ov025_020b574c;

int func_ov025_02085850(void) {
    return data_ov025_020b574c;
}
