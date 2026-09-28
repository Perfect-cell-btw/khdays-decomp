/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_AiState_IntegrateVelocity. */
extern void *Ov107_AiState_IntegrateVelocity(void *self, int factor);

void *func_ov237_020cc800(void *self, int factor)
{
    return Ov107_AiState_IntegrateVelocity(self, factor);
}
