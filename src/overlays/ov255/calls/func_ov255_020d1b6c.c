/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_PostTickBase. */
extern void *Ov107_AiState_PostTickBase();

void *func_ov255_020d1b6c() {
    return Ov107_AiState_PostTickBase();
}
