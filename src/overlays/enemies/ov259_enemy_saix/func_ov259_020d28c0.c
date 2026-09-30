/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_DestroyObject. */
extern void *Ov107_DestroyObject(void *self);

void *func_ov259_020d28c0(void *self)
{
    return Ov107_DestroyObject(self);
}
