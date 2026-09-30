/* Runs the shared per-frame object tick (Ov107_ProcessObjectTick) and returns its result. */

extern int Ov107_ProcessObjectTick(void *self, int delta);

int func_ov177_020d3bfc(void *self, int delta)
{
    return Ov107_ProcessObjectTick(self, delta);
}
