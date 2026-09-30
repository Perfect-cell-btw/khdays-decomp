/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_OnMessage. */
extern void *Ov107_AiState_OnMessage(void *self, void *msg, int size);

void *func_ov292_020d3ac0(void *self, void *msg, int size)
{
    return Ov107_AiState_OnMessage(self, msg, size);
}
