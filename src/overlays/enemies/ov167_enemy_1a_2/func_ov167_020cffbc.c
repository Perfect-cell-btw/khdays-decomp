/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_ProcessObjectTick. */
extern void *Ov107_ProcessObjectTick();

void *func_ov167_020cffbc() {
    return Ov107_ProcessObjectTick();
}
