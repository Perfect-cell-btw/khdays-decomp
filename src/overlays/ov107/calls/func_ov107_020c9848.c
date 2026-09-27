/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to data_ov107_020cbf1c. */
extern int data_ov107_020cbf1c;

int func_ov107_020c9848(void) {
    return data_ov107_020cbf1c;
}
