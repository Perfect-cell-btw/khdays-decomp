/* AI step: sets the stance bits 0x86 and contact flags, sends the action 0x4a update and continues
 * with queuing action 0. */

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov147_AiStep_QueueAction0(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct ov147_LowByteFlags { unsigned bits : 8; };

void Ov147_Action4A_Enter(int *node) {
    int *state = (int *)node[1];
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) |= 3;
    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10);
    }
    ((struct ov147_LowByteFlags *)(*(int *)(*state + 0x38c) + 8))->bits &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x4a, *state + 0x74);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov147_AiStep_QueueAction0);
}
