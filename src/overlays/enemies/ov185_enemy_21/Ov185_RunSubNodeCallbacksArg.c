/*
 * Ov185_RunSubNodeCallbacksArg -- x3 (ov185/186/187). Prime the group, then run each sub-node's +0x1f0
 * callback with the group arg. Call 020c887c(self); for i in 0..3, node = (*(self+0x390))[i], and
 * if node has a callback at +0x1f0, invoke cb(node, arg).
 */
extern void Ov107_LoadMsUpRecord(int self);

void Ov185_RunSubNodeCallbacksArg(int self, int arg) {
    int i;

    Ov107_LoadMsUpRecord(self);
    for (i = 0; i < 4; i++) {
        int node = (*(int **)(self + 0x390))[i];
        void (*cb)(int, int) = *(void (**)(int, int))(node + 0x1f0);

        if (cb != 0) {
            cb(node, arg);
        }
    }
}
