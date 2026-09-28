/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_ProcessObjectTick. */
extern void *Ov107_ProcessObjectTick();

void *func_ov166_020cc37c() {
    return Ov107_ProcessObjectTick();
}
