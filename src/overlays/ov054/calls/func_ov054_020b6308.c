/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov054_BindRig. */
extern void *Ov054_BindRig();

void *func_ov054_020b6308() {
    return Ov054_BindRig();
}
