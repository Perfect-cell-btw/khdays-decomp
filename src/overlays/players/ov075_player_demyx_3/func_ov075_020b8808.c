/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov075_BindRig. */
extern void *Ov075_BindRig();

void *func_ov075_020b8808() {
    return Ov075_BindRig();
}
