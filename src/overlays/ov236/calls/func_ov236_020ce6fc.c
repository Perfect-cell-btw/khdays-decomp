/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_PostTickBase. */
extern void *Ov107_AiState_PostTickBase();

void *func_ov236_020ce6fc() {
    return Ov107_AiState_PostTickBase();
}
