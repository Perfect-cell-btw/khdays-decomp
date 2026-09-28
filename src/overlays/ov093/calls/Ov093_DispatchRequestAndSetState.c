extern void Ov093_BindAttachAnchor(int a, int *b);
extern void Ov093_StartAnimTracks(int a, int *b);
extern void Ov093_Activate(int a, int *b);
extern void Ov022_SetAnimState(int a, int b);
extern int data_ov093_020bc3c0;

void Ov093_DispatchRequestAndSetState(int self, int req) {
    int *blk = (int *)(*(int *)&data_ov093_020bc3c0 + 0x2c + 0x2c00);
    int st = -1;
    int doAnim = 1;
    switch (req) {
    case 0x2e:
        if (*(int *)(self + 0x6bc) != req) {
            Ov093_BindAttachAnchor(self, blk);
        }
        break;
    case 0x2f:
        blk[0x45] = 0;
        if (*(int *)(self + 0x6bc) != req) {
            Ov093_StartAnimTracks(self, blk);
        }
        break;
    case 0x30:
        blk[0x45] = 1;
        if (*(int *)(self + 0x6bc) == req) {
            doAnim = 0;
        } else {
            Ov093_Activate(self, blk);
            Ov093_StartAnimTracks(self, blk);
        }
        st = 0x30;
        req = 0x2f;
        break;
    }
    if (doAnim != 0) {
        Ov022_SetAnimState(self, req);
    }
    if (st >= 0) {
        *(int *)(self + 0x6bc) = st;
    }
}
