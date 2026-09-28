extern void G3dGlb_ComputeInvBaseMtx(void);
extern int data_02047394[];
extern int data_0204749c[];

/* Lazy one-time init (guarded by bit 0x80 at +0xd4), then return the resource. */
int GetOrInitResource749c(void) {
    if ((data_02047394[0x35] & 0x80) == 0) {
        G3dGlb_ComputeInvBaseMtx();
        data_02047394[0x35] |= 0x80;
    }
    return (int)data_0204749c;
}
