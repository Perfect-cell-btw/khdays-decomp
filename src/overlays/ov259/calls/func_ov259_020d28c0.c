/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_DestroyObject. */
extern void *Ov107_DestroyObject();

void *func_ov259_020d28c0() {
    return Ov107_DestroyObject();
}
