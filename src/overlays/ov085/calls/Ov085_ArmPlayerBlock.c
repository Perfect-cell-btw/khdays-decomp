/* Sets the local player's lock bits and arms the build block with the value. */

extern int Session_GetLocalPlayerIndex(void);
extern int Ov022_ActorSetState(int *self, int state);
extern int data_ov085_020b9260;

int Ov085_ArmPlayerBlock(int *self, int v) {
    int *blk = (int *)(*(int *)&data_ov085_020b9260 + 0xc50 + 0x2000);
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x46c) |= 0x10000;
    }
    blk[0] = v;
    blk[1] = 1;
    *(int *)((char *)blk + 0x120) = 0;
    blk[2] = 0;
    *(int *)((char *)blk + 0x124) = 0;
    return Ov022_ActorSetState(self, 0x21);
}
