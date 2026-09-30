/*
 * Ov185_NotifyAndDoubleAngle -- x3 (ov185/186/187). Notify each sub-node's +0x1ec callback, then double
 * its stored angle (mod 2^15). Call 020c8500(self); for i in 0..3, node = (*(self+0x390))[i]: if
 * node has a callback at +0x1ec, call cb(node, arg); then reload node, read the signed halfword at
 * +0x218, set both +0x218 and +0x21a to (short)(v << 1).
 */
extern void Ov107_AiState_LoadStats(int self, int recordIndex);

void Ov185_NotifyAndDoubleAngle(int self, int arg) {
    int i;

    Ov107_AiState_LoadStats(self, arg);
    for (i = 0; i < 4; i++) {
        int node = (*(int **)(self + 0x390))[i];
        void (*cb)(int, int) = *(void (**)(int, int))(node + 0x1ec);
        short v;

        if (cb != 0) {
            cb(node, arg);
        }
        node = (*(int **)(self + 0x390))[i];
        v = (short)(*(short *)(node + 0x218) << 1);
        *(short *)(node + 0x218) = v;
        *(short *)(node + 0x21a) = v;
    }
}
