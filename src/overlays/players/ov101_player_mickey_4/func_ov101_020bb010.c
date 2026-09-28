/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov101_BindRig. */
extern void *Ov101_BindRig();

void *func_ov101_020bb010() {
    return Ov101_BindRig();
}
