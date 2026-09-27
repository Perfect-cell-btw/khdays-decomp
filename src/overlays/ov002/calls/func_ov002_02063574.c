/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov002_020646d4. */
extern void *func_ov002_020646d4();

void *func_ov002_02063574() {
    return func_ov002_020646d4();
}
