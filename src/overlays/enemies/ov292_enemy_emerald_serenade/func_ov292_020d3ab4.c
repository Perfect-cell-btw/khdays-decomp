/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_ProcessObjectTick. */
extern void *Ov107_ProcessObjectTick(void *self, int delta);

void *func_ov292_020d3ab4(void *self, int delta)
{
    return Ov107_ProcessObjectTick(self, delta);
}
