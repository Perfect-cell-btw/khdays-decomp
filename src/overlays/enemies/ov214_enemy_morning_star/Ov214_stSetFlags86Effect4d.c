/* State step: clears bit 0 and sets the stance bits in the high byte of the actor's flags (+0x60),
 * sets bits 0-1 of +0x1ae, clears bit 0 of the part's flag byte, sends a state update and installs
 * the queue-action-0 step. */

struct hw60 { unsigned short lo : 8, hi : 8; };
struct bf { unsigned b : 8; };
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov214_AiStep_QueueAction0(void);

void Ov214_stSetFlags86Effect4d(int *node) {
    int *state = (int *)node[1];
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) |= 3;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*state + 0x3ac) + 8))->b &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x4d, *state + 0x74);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov214_AiStep_QueueAction0);
}
