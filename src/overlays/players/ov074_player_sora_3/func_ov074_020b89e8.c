/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov074_BindRig. */
extern void *Ov074_BindRig();

void *func_ov074_020b89e8(char *self) {
    return Ov074_BindRig(self);
}
