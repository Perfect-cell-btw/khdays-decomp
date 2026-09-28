/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov035_BindRig. */
extern void *Ov035_BindRig();

void *func_ov035_020b3b08(char *self) {
    return Ov035_BindRig(self);
}
