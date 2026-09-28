/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov055_BindRig. */
extern void *Ov055_BindRig();

void *func_ov055_020b6128() {
    return Ov055_BindRig();
}
