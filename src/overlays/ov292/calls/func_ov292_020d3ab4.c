/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_ProcessObjectTick. */
extern void *Ov107_ProcessObjectTick();

void *func_ov292_020d3ab4() {
    return Ov107_ProcessObjectTick();
}
