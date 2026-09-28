/* Maps an animation request to the effect block (0x2e anchors, 0x2f starts the tracks, 0x30
 * activates and starts them), applies the animation state and keeps 0x30 as the current code when
 * asked. */

extern void Ov037_BindAttachAnchor(int a, int *b);
extern void Ov037_StartAnimTracks(int a, int *b);
extern void Ov037_Activate(int a, int *b);
extern void Ov022_SetAnimState(int a, int b);
extern int data_ov037_020b4e20;

void Ov037_DispatchRequestAndSetState(int self, int req) {
    int *blk = (int *)(*(int *)&data_ov037_020b4e20 + 0x2c + 0x2c00);
    int st = -1;
    int doAnim = 1;
    switch (req) {
    case 0x2e:
        if (*(int *)(self + 0x6bc) != req) {
            Ov037_BindAttachAnchor(self, blk);
        }
        break;
    case 0x2f:
        blk[0x45] = 0;
        if (*(int *)(self + 0x6bc) != req) {
            Ov037_StartAnimTracks(self, blk);
        }
        break;
    case 0x30:
        blk[0x45] = 1;
        if (*(int *)(self + 0x6bc) == req) {
            doAnim = 0;
        } else {
            Ov037_Activate(self, blk);
            Ov037_StartAnimTracks(self, blk);
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
