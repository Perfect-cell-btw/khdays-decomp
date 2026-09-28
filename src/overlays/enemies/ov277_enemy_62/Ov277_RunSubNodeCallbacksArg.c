/*
 * Ov277_RunSubNodeCallbacksArg -- x3 (ov185/186/187). Prime the group, then run each sub-node's +0x1ec
 * callback with the group arg. Call 020c887c(self); for i in 0..3, node = (*(self+0x400))[i], and
 * if node has a callback at +0x1ec, invoke cb(node, arg).
 */
extern void Ov107_AiState_LoadStats(int self);

void Ov277_RunSubNodeCallbacksArg(int self, int arg) {
    int i;

    Ov107_AiState_LoadStats(self);
    for (i = 0; i < 2; i++) {
        int node = (*(int **)(self + 0x400))[i];
        void (*cb)(int, int) = *(void (**)(int, int))(node + 0x1ec);

        if (cb != 0) {
            cb(node, arg);
        }
    }
}
