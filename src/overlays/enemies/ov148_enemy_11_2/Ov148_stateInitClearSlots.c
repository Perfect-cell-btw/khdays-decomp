/* Initialise a spawned child: point its +4 at obj+0xb0, reset state bytes +0x1c6/+0x1c7, clear the
 * low bit of its high-byte flags at +0x60 and of the u16 at +0x1ae, then run the 0/1/2 dispatch
 * sequence. */

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov148_dispatchByStatusByteReset(void);
extern void Ov148_ResetPoseAndFlags(void);
extern void Ov148_PublishVelocity_Step(void);
void Ov148_stateInitClearSlots(int *node) {
    int *state = (int *)node[1];
    state[1] = *state + 0xb0;
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = 0xff;
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    SetIndexedSlot(node, 0, Ov148_dispatchByStatusByteReset);
    SetIndexedSlot(node, 1, Ov148_ResetPoseAndFlags);
    SetIndexedSlot(node, 2, Ov148_PublishVelocity_Step);
}
