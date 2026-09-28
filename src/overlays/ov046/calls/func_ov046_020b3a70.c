/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov046_BindRig. */
extern void *Ov046_BindRig();

void *func_ov046_020b3a70() {
    return Ov046_BindRig();
}
