/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_OnSyncMessage. */
extern void *Ov107_AiState_OnSyncMessage(int self, void *msg);

void *func_ov210_020d3f1c(int self, void *msg)
{
    return Ov107_AiState_OnSyncMessage(self, msg);
}
