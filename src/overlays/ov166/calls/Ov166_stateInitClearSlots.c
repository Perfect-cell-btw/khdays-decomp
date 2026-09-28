/* Initialise a spawned child: point its +8 at obj+0xb0, reset state bytes +0x1c6/+0x1c7, clear the
 * low bit of its high-byte flags at +0x60 and of the u16 at +0x1ae, then run the 0/1/2 dispatch
 * sequence. */

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov166_dispatchByStatusByteReset(void);
extern void Ov166_ConfigHw60CopyVec3ConstToCThenAdvance(void);
extern void Ov166_AiApplyMoveVector(void);
void Ov166_stateInitClearSlots(int *node) {
    int *state = (int *)node[1];
    state[2] = *state + 0xb0;
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = 0xff;
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    SetIndexedSlot(node, 0, Ov166_dispatchByStatusByteReset);
    SetIndexedSlot(node, 1, Ov166_ConfigHw60CopyVec3ConstToCThenAdvance);
    SetIndexedSlot(node, 2, Ov166_AiApplyMoveVector);
}
