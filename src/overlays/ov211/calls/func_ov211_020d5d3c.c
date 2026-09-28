/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_OnSyncMessage. */
extern void *Ov107_AiState_OnSyncMessage();

void *func_ov211_020d5d3c() {
    return Ov107_AiState_OnSyncMessage();
}
