extern void G3dGlb_ComputeInvBaseMtx(void);
extern int data_02047394[];
extern int data_020474cc[];

/* Lazy one-time init (guarded by bit 0x80 at +0xd4), then return the resource. */
int GetOrInitResource74cc(void) {
    if ((data_02047394[0x35] & 0x80) == 0) {
        G3dGlb_ComputeInvBaseMtx();
        data_02047394[0x35] |= 0x80;
    }
    return (int)data_020474cc;
}
