/* AI step: clears bit 0 and sets the stance bits in the high byte of the actor's flags (+0x60),
 * sets bits 0-1 of +0x1ae, clears bit 0 of its model's flag byte, sends a state update, clears the
 * pending action and clears the step handler. */

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct ov114_LowByteFlags { unsigned bits : 8; };

void Ov244_Action6Callback(int *node) {
    int *state = (int *)node[1];
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10);
    }
    *(unsigned short *)(*state + 0x1ae) |= 3;
    ((struct ov114_LowByteFlags *)(*(int *)(*state + 0x388) + 8))->bits &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0x112, 6, state[2]);
    *(signed char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), 0);
}
