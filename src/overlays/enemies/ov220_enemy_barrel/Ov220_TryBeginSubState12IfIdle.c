/* Reaction check: requests a fixed sub-state as the pending action (+0x1c7) when no action is
 * pending; returns whether it did. */

struct sc1c7 { signed char _pad[0x1c7]; signed char status; };

int Ov220_TryBeginSubState12IfIdle(int this_) {
    int node = *(int *)(*(int *)(this_ + 0x214));
    int neg = -1;
    if (((struct sc1c7 *)node)->status == neg) {
        ((struct sc1c7 *)node)->status = 0xc;
        return 1;
    }
    return 0;
}
