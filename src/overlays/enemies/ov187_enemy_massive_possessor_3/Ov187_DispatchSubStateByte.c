/* State dispatcher: when an action is pending (+0x1c7 not -1) resets the per-action flags and the
 * model's rotation, makes it current (+0x1c6) and installs the step that starts that action; then
 * marks nothing pending. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Srt_SetRotationQuat(int a, void *b);
extern int data_020420f8;
extern void Ov187_stateSetFlagsClearBit_2(void);
extern void Ov187_AcquireAimTransform_2(void);
extern void Ov187_PickRandomSignedSpeed(void);
extern void Ov187_SetPoseThenAdvanceSlot(void);
extern void Ov187_BuildTransformMatrixThenAdvance_2(void);
extern void Ov187_AiEndWithUpdate_2(void);
extern void Ov187_SeedTimerFireThenAdvanceSlot(void);
extern void Ov187_BeginTumble(void);
extern void Ov187_AiEnterDown(void);
extern void Ov187_AiEnterDefeat(void);

void Ov187_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        { unsigned short *p = (unsigned short *)(*state + 0x60); unsigned int u = *p;
          *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10)); }
        ((struct hw60 *)(*state + 0x60))->hi &= ~0x8e;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
        Srt_SetRotationQuat(*(int *)(*state + 0x384) + 4, &data_020420f8);
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0: SetIndexedSlot(node, 1, Ov187_stateSetFlagsClearBit_2); break;
        case 1: SetIndexedSlot(node, 1, Ov187_AcquireAimTransform_2); break;
        case 2: SetIndexedSlot(node, 1, Ov187_PickRandomSignedSpeed); break;
        case 4: SetIndexedSlot(node, 1, Ov187_SetPoseThenAdvanceSlot); break;
        case 5: SetIndexedSlot(node, 1, Ov187_BuildTransformMatrixThenAdvance_2); break;
        case 3: SetIndexedSlot(node, 1, Ov187_AiEndWithUpdate_2); break;
        case 6: SetIndexedSlot(node, 1, Ov187_SeedTimerFireThenAdvanceSlot); break;
        case 7: SetIndexedSlot(node, 1, Ov187_BeginTumble); break;
        case 8: SetIndexedSlot(node, 1, Ov187_AiEnterDown); break;
        case 9: SetIndexedSlot(node, 1, Ov187_AiEnterDefeat); break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
