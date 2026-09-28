/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_OnDefeat. */
extern void *Ov107_AiState_OnDefeat();

void *func_ov244_020cd20c() {
    return Ov107_AiState_OnDefeat();
}
