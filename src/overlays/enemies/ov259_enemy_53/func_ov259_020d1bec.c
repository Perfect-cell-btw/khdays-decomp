/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_PostTickBase. */
extern void *Ov107_AiState_PostTickBase();

void *func_ov259_020d1bec() {
    return Ov107_AiState_PostTickBase();
}
