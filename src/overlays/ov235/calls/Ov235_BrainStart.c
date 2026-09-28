/* Brain start of the ov235 enemy: sub-state 0 with none pending, the +0x1c and +0x2c orientations
 * reset to the identity quaternion, the +4/+8/+0xc shortcuts point at the owner's +0x74 point,
 * +0xb0 point and its rig's +0xad busy byte, +0x88 is set, and the three slots get their ticks
 * (1: Ov235_stateSetFlagsClearBit, 0: Ov235_AiDispatchAction, 2: Ov235_BodyTick). */
typedef struct { int w[4]; } Quat;

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const Quat data_020420f8;
extern void Ov235_stateSetFlagsClearBit(int *node);
extern void Ov235_AiDispatchAction(int *node);
extern void Ov235_BodyTick(int *node);

void Ov235_BrainStart(int *node)
{
    int *state = (int *)node[1];

    *(unsigned char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    *(Quat *)(state + 7) = data_020420f8;
    *(Quat *)(state + 0xb) = *(Quat *)(state + 7);
    state[1] = *state + 0x74;
    state[2] = *state + 0xb0;
    state[3] = *(int *)(*state + 0x384) + 0xad;
    state[0x22] = 1;
    SetIndexedSlot(node, 1, (void *)Ov235_stateSetFlagsClearBit);
    SetIndexedSlot(node, 0, (void *)Ov235_AiDispatchAction);
    SetIndexedSlot(node, 2, (void *)Ov235_BodyTick);
}
