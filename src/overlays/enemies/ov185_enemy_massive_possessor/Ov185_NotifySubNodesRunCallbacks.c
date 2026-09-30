/*
 * Ov185_NotifySubNodesRunCallbacks -- x3 (ov185/186/187). Notify each of the 4 sub-nodes, run its callback,
 * then clear a flag word; finish by ticking the owner. For i in 0..3, node = (*(self+0x390))[i]:
 * ping the owner via 020c2b20(arg, node); if node has a callback at +0x1f0, call cb(node,
 * *(u8)(self+0x19e)); then zero node+0x220. Hand off with 020c7b70(self, arg).
 */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(int self, int arg);

void Ov185_NotifySubNodesRunCallbacks(int self, int arg) {
    int i;

    for (i = 0; i < 4; i++) {
        int node = (*(int **)(self + 0x390))[i];
        void (*cb)(int, unsigned char);
        unsigned char b;

        Ov107_InitObjectFromSource(arg, node);
        node = (*(int **)(self + 0x390))[i];
        b = ((unsigned char *)self)[0x19e];
        cb = *(void (**)(int, unsigned char))(node + 0x1f0);
        if (cb != 0) {
            cb(node, b);
        }
        node = (*(int **)(self + 0x390))[i];
        *(int *)(node + 0x220) = 0;
    }
    Ov107_HandleRegionEvent(self, arg);
}
