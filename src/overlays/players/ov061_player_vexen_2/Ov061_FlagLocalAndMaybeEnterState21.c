extern int Session_GetLocalPlayerIndex(void);
extern int Ov022_IsSlotReady(int a);
extern int Ov022_AreStreamsIdle(int a);
extern int Ov022_ActorSetState(int self, int state);
extern int data_ov061_020b7000;

int Ov061_FlagLocalAndMaybeEnterState21(int self) {
    int ret = 0;
    int *blk = (int *)(*(int *)&data_ov061_020b7000 + 0x2c + 0x2c00);
    int ok = 1;
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x46c) |= 0x10000;
    }
    blk[2] = Ov022_IsSlotReady(self + 0x2f8 + 0x2000);
    if (blk[2] != 0) {
        if (Ov022_AreStreamsIdle(*(int *)(self + 0x2000 + 0x644) + 0x30) == 0) {
            ok = 0;
        }
    }
    if (ok != 0) {
        ret = Ov022_ActorSetState(self, 0x21);
    }
    return ret;
}
