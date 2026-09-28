/* State step: clears bit 0 and sets the stance bits in the high byte of the actor's flags (+0x60),
 * sets bits 0-1 of +0x1ae, clears bit 0 of the model's flag byte, sends a state update and installs
 * the queue-action-0 step. */

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov197_AiStep_QueueAction0(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct ov197b_LowByteFlags { unsigned bits : 8; };

void Ov197_Action4B_Enter(int *node) {
    int *state = (int *)node[1];
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) |= 3;
    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10);
    }
    ((struct ov197b_LowByteFlags *)(*(int *)(*state + 0x38c) + 8))->bits &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x4b, *state + 0x74);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov197_AiStep_QueueAction0);
}
