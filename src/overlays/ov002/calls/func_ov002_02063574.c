/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov002_StateGuardStub. */
extern void *Ov002_StateGuardStub();

void *func_ov002_02063574() {
    return Ov002_StateGuardStub();
}
