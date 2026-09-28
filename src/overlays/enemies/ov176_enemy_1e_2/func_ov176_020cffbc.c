/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_ProcessObjectTick. */
extern void *Ov107_ProcessObjectTick(void *self, int delta);

void *func_ov176_020cffbc(void *self, int delta)
{
    return Ov107_ProcessObjectTick(self, delta);
}
