/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov036_BindRig. */
extern void *Ov036_BindRig();

void *func_ov036_020b3928() {
    return Ov036_BindRig();
}
