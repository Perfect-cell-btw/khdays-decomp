extern int Session_GetLocalPlayerIndex(void);
extern int Ov022_ActorSetState(int *self, int state);
extern int data_ov056_020b7620;

int Ov056_PublishAltAndEnterState(int *self, int alt) {
    char *blk = (char *)(*(int *)&data_ov056_020b7620 + 0x2c + 0x2c00);
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x46c) |= 0x10000;
    }
    *(int *)(blk + 0x114) = alt;
    if (alt != 0) {
        return Ov022_ActorSetState(self, 0x22);
    }
    return Ov022_ActorSetState(self, 0x21);
}
