/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_OnSyncMessage. */
extern void *Ov107_AiState_OnSyncMessage();

void *func_ov210_020d3f1c() {
    return Ov107_AiState_OnSyncMessage();
}
