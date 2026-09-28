/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov025_GetVarRecordByIndex. */
extern void *Ov025_GetVarRecordByIndex();

void *func_ov025_0208a26c() {
    return Ov025_GetVarRecordByIndex();
}
