/* AI step: sets the stance bits 0x86 and contact flags, sends the update (0x159, mode 6), queues
 * action 0 and ends the step. */

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct ov250_LowByteFlags { unsigned bits : 8; };

void Ov250_Action6Callback(int *node) {
    int *state = (int *)node[1];
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10);
    }
    *(unsigned short *)(*state + 0x1ae) |= 3;
    ((struct ov250_LowByteFlags *)(*(int *)(*state + 0x388) + 8))->bits &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0x159, 6, state[2]);
    *(signed char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), 0);
}
