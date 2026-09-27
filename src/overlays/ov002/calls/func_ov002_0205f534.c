/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to data_ov002_0207eb24. */
extern int data_ov002_0207eb24;

int func_ov002_0205f534(void) {
    return data_ov002_0207eb24;
}
