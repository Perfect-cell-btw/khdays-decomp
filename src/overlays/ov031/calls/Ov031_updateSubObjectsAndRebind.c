extern void Ov031_ActorNodeTick(int this, int slot, int p3);
extern int Ov022_IsState9Or6WithFlag200(int x);
extern int Ov022_IsSlotReady(int x);
extern void Ov031_ResetChannelsAndArm(int p);

void Ov031_updateSubObjectsAndRebind(int this, int base, int p3) {
    int i;
    int slot;
    slot = base + 0xc;
    i = 0;
    do {
        Ov031_ActorNodeTick(this, slot, p3);
        i++;
        slot += 0x118;
    } while (i < 2);
    if (Ov022_IsState9Or6WithFlag200(this + 0x22f8) == 0) return;
    if (*(int *)(base + 0x128) == 0) {
        Ov031_ResetChannelsAndArm(base + 0x124);
    }
    if (Ov022_IsSlotReady(this + 0x22f8) == 0) return;
    if (*(int *)(base + 0x10) != 0) return;
    Ov031_ResetChannelsAndArm(base + 0xc);
}
