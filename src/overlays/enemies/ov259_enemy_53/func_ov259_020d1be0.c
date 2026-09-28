/* Forwards a message to the shared AI message handler (Ov107_AiState_OnMessage). */

extern int Ov107_AiState_OnMessage(void *self, void *msg, int size);

int func_ov259_020d1be0(void *self, void *msg, int size)
{
    return Ov107_AiState_OnMessage(self, msg, size);
}
