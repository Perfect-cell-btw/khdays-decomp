/* Runs the shared per-frame object tick (Ov107_ProcessObjectTick) and returns its result. */

extern int Ov107_ProcessObjectTick(void *self, int delta);

int func_ov277_020d0e14(void *self, int delta)
{
    return Ov107_ProcessObjectTick(self, delta);
}
