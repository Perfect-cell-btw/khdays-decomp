/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov092_BindRig. */
extern void *Ov092_BindRig();

void *func_ov092_020baec8(char *self) {
    return Ov092_BindRig(self);
}
