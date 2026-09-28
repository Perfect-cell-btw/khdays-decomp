/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov058_BindRig. */
extern void *Ov058_BindRig();

void *func_ov058_020b6680(char *self) {
    return Ov058_BindRig(self);
}
