/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_OnMessage. */
extern void *Ov107_AiState_OnMessage();

void *func_ov292_020d3ac0() {
    return Ov107_AiState_OnMessage();
}
