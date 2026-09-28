extern int Session_GetLocalPlayerIndex(void);
extern int Ov022_ActorSetState(int obj, int mode);

int Ov022_TryAdvanceAndClearBit11(int obj) {
    int r = 0;
    if (Session_GetLocalPlayerIndex() == 0)
        *(unsigned long long *)(obj + 0x464) |= 0x200000000LL;
    if (Session_GetLocalPlayerIndex() == 0)
        *(unsigned long long *)(obj + 0x464) |= 0x4000000000LL;
    *(int *)(obj + 0x4b4) = 0x3000;
    if ((*(unsigned long long *)obj & 0x800LL) == 0) r = Ov022_ActorSetState(obj, 0);
    if (r != 0)
        *(unsigned long long *)obj &= ~0x800LL;
    return r;
}
