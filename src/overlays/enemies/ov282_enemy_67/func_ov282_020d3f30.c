/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_OnSyncMessage. */
extern void *Ov107_AiState_OnSyncMessage(int self, void *msg);

void *func_ov282_020d3f30(int self, void *msg)
{
    return Ov107_AiState_OnSyncMessage(self, msg);
}
