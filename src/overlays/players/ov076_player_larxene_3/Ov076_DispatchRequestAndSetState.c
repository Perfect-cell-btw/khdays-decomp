extern void Ov076_BindAttachAnchor(int a, int *b);
extern void Ov076_StartAnimTracks(int a, int *b);
extern void Ov076_Activate(int a, int *b);
extern void Ov022_SetAnimState(int a, int b);
extern int data_ov076_020b9d00;

void Ov076_DispatchRequestAndSetState(int self, int req) {
    int *blk = (int *)(*(int *)&data_ov076_020b9d00 + 0x2c + 0x2c00);
    int st = -1;
    int doAnim = 1;
    switch (req) {
    case 0x2e:
        if (*(int *)(self + 0x6bc) != req) {
            Ov076_BindAttachAnchor(self, blk);
        }
        break;
    case 0x2f:
        blk[0x45] = 0;
        if (*(int *)(self + 0x6bc) != req) {
            Ov076_StartAnimTracks(self, blk);
        }
        break;
    case 0x30:
        blk[0x45] = 1;
        if (*(int *)(self + 0x6bc) == req) {
            doAnim = 0;
        } else {
            Ov076_Activate(self, blk);
            Ov076_StartAnimTracks(self, blk);
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
