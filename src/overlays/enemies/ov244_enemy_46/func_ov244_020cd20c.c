/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_OnDefeat. */
extern void *Ov107_AiState_OnDefeat(void *self);

void *func_ov244_020cd20c(void *self)
{
    return Ov107_AiState_OnDefeat(self);
}
