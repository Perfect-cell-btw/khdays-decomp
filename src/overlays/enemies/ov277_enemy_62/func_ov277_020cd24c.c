/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_OnDefeat. */
extern void *Ov107_AiState_OnDefeat(void *self);

void *func_ov277_020cd24c(void *self)
{
    return Ov107_AiState_OnDefeat(self);
}
