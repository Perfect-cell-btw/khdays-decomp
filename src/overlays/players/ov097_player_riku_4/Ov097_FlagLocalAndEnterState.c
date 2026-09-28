extern int Session_GetLocalPlayerIndex(void);
extern int Ov022_ActorSetState(int *self, int state);

int Ov097_FlagLocalAndEnterState(int *self, int alt) {
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x46c) |= 0x10000;
    }
    if (alt != 0) {
        return Ov022_ActorSetState(self, 0x22);
    }
    return Ov022_ActorSetState(self, 0x21);
}
