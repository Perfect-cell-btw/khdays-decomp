extern void Ov022_ToggleBit13ByMode(int obj, int mode);
extern void Ov022_ActorSetState(int obj, int mode);

void Ov022_ResolveGuardBreakState(int obj) {
    Ov022_ToggleBit13ByMode(obj, 0);
    if ((*(unsigned int *)(obj + 0x24) & 4) != 0) {
        if ((int)*(unsigned int *)(obj + 0x480) <= 0 &&
            *(unsigned int *)(obj + 0x58) == 0x80000000) {
            *(unsigned long long *)obj &= ~0x2000000LL;
            Ov022_ActorSetState(obj, 4);
            return;
        }
        *(unsigned long long *)obj |= 0x2000000LL;
        Ov022_ActorSetState(obj, 5);
        return;
    }
    if (*(unsigned int *)(obj + 0x480) != 0) {
        *(unsigned long long *)obj |= 0x2000000LL;
    } else {
        *(unsigned long long *)obj &= ~0x2000000LL;
        *(int *)(obj + 0x58) = 0x400;
    }
    Ov022_ActorSetState(obj, 5);
}
