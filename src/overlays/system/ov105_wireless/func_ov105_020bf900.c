/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov105_WH_StateInSetMPData. */
extern void *Ov105_WH_StateInSetMPData();

void *func_ov105_020bf900() {
    return Ov105_WH_StateInSetMPData();
}
