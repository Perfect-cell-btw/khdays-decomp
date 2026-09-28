/* Sub-state dispatcher of the ov144 enemy (and its byte-identical twin). While ready (bit 0 of
 * the +0x60 flag) with no pending request and outside sub-states 4-7, a spawnable piece found by
 * ccb34 becomes the +4 target, its +0x18c item is activated and sub-state 5 is requested. A
 * pending +0x1c7 request then becomes the +0x1c6 sub-state: the +0x3f4 flag is set except in
 * sub-states 4/6/7/8, bit 0 of +0x1ae and bits 1/7 of the +0x60 high byte clear, bits 2/3/6 set,
 * slot 1 takes the state's tick (0 spawn setup, 2 charge decision, 3/4 recover, 5-7 aim hold,
 * 8 hold, 9 retreat) and the request is cleared. */
struct hw60 { unsigned short lo : 8, hi : 8; };

extern int Ov145_FindPiece(int *node);
extern void func_ov022_020ad838(int item, int on);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov145_stSetDispFlags86(int *node);
extern void Ov145_ChargeDecision(int *node);
extern void Ov145_BeginRecover(int *node);
extern void Ov145_PoseThenAction4OrIdle(int *node);
extern void Ov145_SetPose3ThenAdvanceSlot(int *node);
extern void Ov145_BeginRetreat(int *node);

void Ov145_SubStateDispatch(int *node)
{
    int *state = (int *)node[1];
    int actor;
    signed char next;
    unsigned short *hw;
    unsigned int h;

    actor = *state;
    if ((((struct hw60 *)(actor + 0x60))->lo & 1) != 0 && *(signed char *)(actor + 0x1c7) == -1) {
        switch (*(signed char *)(actor + 0x1c6)) {
        case 0:
        case 1:
        case 2:
        case 3:
        default:
            state[1] = Ov145_FindPiece(node);
            if (state[1] != 0) {
                func_ov022_020ad838(*(int *)(state[1] + 0x18c), 1);
                *(unsigned char *)(*state + 0x1c7) = 5;
            }
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        }
    }
    next = *(signed char *)(*state + 0x1c7);
    if (next == -1) {
        return;
    }
    *(signed char *)(*state + 0x1c6) = next;
    actor = *state;
    switch (*(signed char *)(actor + 0x1c6)) {
    case 4:
    case 6:
    case 7:
    case 8:
        *(int *)(actor + 0x3f4) = 0;
        break;
    default:
        *(int *)(actor + 0x3f4) = 1;
        break;
    }
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x82;
    hw = (unsigned short *)(*state + 0x60);
    h = *hw;
    *hw = h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 0x4c) << 0x18) >> 0x10);
    switch (*(signed char *)(*state + 0x1c6)) {
    case 0:
        SetIndexedSlot(node, 1, Ov145_stSetDispFlags86);
        break;
    case 2:
        SetIndexedSlot(node, 1, Ov145_ChargeDecision);
        break;
    case 3:
        SetIndexedSlot(node, 1, Ov145_BeginRecover);
        break;
    case 4:
        SetIndexedSlot(node, 1, Ov145_BeginRecover);
        break;
    case 5:
        SetIndexedSlot(node, 1, Ov145_PoseThenAction4OrIdle);
        break;
    case 6:
        SetIndexedSlot(node, 1, Ov145_PoseThenAction4OrIdle);
        break;
    case 7:
        SetIndexedSlot(node, 1, Ov145_PoseThenAction4OrIdle);
        break;
    case 8:
        SetIndexedSlot(node, 1, Ov145_SetPose3ThenAdvanceSlot);
        break;
    case 9:
        SetIndexedSlot(node, 1, Ov145_BeginRetreat);
        break;
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
