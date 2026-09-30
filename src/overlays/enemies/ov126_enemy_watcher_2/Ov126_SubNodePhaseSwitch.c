/* Phase switch of the ov125 enemy's sub-node: the +0x34 word holds the current phase (low
 * signed nibble) and the pending one (next nibble). In phases 1/2 an owner +0x1ac bit 1 hit
 * cancels the pending phase, and any +0x1c4 0xa flag cancels it outside phase 0. When a phase
 * is pending it becomes current and its slot-1 handler is installed (0: ce84c, 1: ce8b4,
 * 2: cf1a8), after which the pending nibble is reset to -1. */
struct Phase { int cur : 4, next : 4; };

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov126_HideAllParts(void);
extern void Ov126_EnterAimSubNode(void);
extern void Ov126_AiEnterBeamWindDown(void);

void Ov126_SubNodePhaseSwitch(int *node) {
    int *state = (int *)node[1];
    struct Phase *p = (struct Phase *)(state + 0xd);

    if (p->cur == 1 || p->cur == 2) {
        if ((*(unsigned short *)(*state + 0x1ac) & 2) != 0) {
            p->next = 0;
        }
    }
    if ((*(unsigned char *)(*state + 0x1c4) & 0xa) != 0) {
        if (p->cur != 0) {
            p->next = 0;
        }
    }
    if (p->next == -1) {
        return;
    }
    p->cur = p->next;
    switch (p->cur) {
    case 0:
        SetIndexedSlot(node, 1, Ov126_HideAllParts);
        break;
    case 1:
        SetIndexedSlot(node, 1, Ov126_EnterAimSubNode);
        break;
    case 2:
        SetIndexedSlot(node, 1, Ov126_AiEnterBeamWindDown);
        break;
    }
    p->next = -1;
}
