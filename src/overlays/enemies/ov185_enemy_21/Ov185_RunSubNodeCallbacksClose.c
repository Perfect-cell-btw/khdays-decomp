/*
 * Ov185_RunSubNodeCallbacksClose -- x3 (ov185/186/187). Run each sub-node's +0x1f8 callback, then close.
 * For i in 0..3, node = (*(self+0x390))[i]; cb = *(node + 0x1f8); if set, call cb(node). Finish
 * with 020c88fc(self).
 */

#include "game/enemy_common.h"

void Ov185_RunSubNodeCallbacksClose(int self) {
    int i;

    for (i = 0; i < 4; i++) {
        int node = (*(int **)(self + 0x390))[i];
        void (*cb)(int) = *(void (**)(int))(node + 0x1f8);

        if (cb != 0) {
            cb(node);
        }
    }
    Ov107_ResetStanceBase((Actor *)self);
}
