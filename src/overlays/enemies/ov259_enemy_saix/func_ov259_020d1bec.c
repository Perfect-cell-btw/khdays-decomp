/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_PostTickBase. */
extern void *Ov107_AiState_PostTickBase(char * self);

void *func_ov259_020d1bec(char * self)
{
    return Ov107_AiState_PostTickBase(self);
}
