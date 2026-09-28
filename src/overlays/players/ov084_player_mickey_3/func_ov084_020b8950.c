/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov084_BindRig. */
extern void *Ov084_BindRig();

void *func_ov084_020b8950(char *self) {
    return Ov084_BindRig(self);
}
