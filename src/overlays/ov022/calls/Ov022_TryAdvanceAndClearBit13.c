extern int Session_GetLocalPlayerIndex(void);
extern int Ov022_ActorSetState(int obj, int mode);

int Ov022_TryAdvanceAndClearBit13(int obj) {
    int r = 0;
    if (Session_GetLocalPlayerIndex() == 0)
        *(unsigned long long *)(obj + 0x464) |= 0x8000LL;
    if ((*(unsigned long long *)obj & 0x2000LL) == 0) {
        if ((*(unsigned int *)(obj + 0x24) & 4) != 0) r = Ov022_ActorSetState(obj, 0);
        else r = Ov022_ActorSetState(obj, 2);
    }
    if (r != 0)
        *(unsigned long long *)obj &= ~0x2000LL;
    return r;
}
