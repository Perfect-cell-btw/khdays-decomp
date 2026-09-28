/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov078_BindRig. */
extern void *Ov078_BindRig();

void *func_ov078_020b8d60() {
    return Ov078_BindRig();
}
