/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_GetVarRecordByIndex. */
extern void *Ov008_GetVarRecordByIndex();

void *func_ov008_0205665c() {
    return Ov008_GetVarRecordByIndex();
}
