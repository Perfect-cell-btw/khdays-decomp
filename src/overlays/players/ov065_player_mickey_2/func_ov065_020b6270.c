/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov065_BindRig. */
extern void *Ov065_BindRig();

void *func_ov065_020b6270() {
    return Ov065_BindRig();
}
