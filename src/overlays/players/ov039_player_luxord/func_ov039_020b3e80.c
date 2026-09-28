/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov039_BindRig. */
extern void *Ov039_BindRig();

void *func_ov039_020b3e80(char *self) {
    return Ov039_BindRig(self);
}
