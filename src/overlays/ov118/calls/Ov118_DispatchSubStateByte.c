struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Srt_SetRotationQuat(int a, void *b);
extern int data_020420f8;
extern void Ov118_stateSetFlagsClearBit(void);
extern void Ov118_AcquireAimTransform(void);
extern void Ov118_PickRandomSignedSpeed(void);
extern void Ov118_SetPose1ThenAdvanceSlot(void);
extern void Ov118_BuildTransformMatrixThenAdvance(void);
extern void Ov118_AiEndWithUpdate(void);
extern void Ov118_SeedTimerFireThenAdvanceSlot(void);
extern void Ov118_BeginTumble(void);
extern void Ov118_AiEnterDown(void);
extern void Ov118_AiEnterDefeat(void);

void Ov118_DispatchSubStateByte(int *node) {
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
        case 0: SetIndexedSlot(node, 1, Ov118_stateSetFlagsClearBit); break;
        case 1: SetIndexedSlot(node, 1, Ov118_AcquireAimTransform); break;
        case 2: SetIndexedSlot(node, 1, Ov118_PickRandomSignedSpeed); break;
        case 4: SetIndexedSlot(node, 1, Ov118_SetPose1ThenAdvanceSlot); break;
        case 5: SetIndexedSlot(node, 1, Ov118_BuildTransformMatrixThenAdvance); break;
        case 3: SetIndexedSlot(node, 1, Ov118_AiEndWithUpdate); break;
        case 6: SetIndexedSlot(node, 1, Ov118_SeedTimerFireThenAdvanceSlot); break;
        case 7: SetIndexedSlot(node, 1, Ov118_BeginTumble); break;
        case 8: SetIndexedSlot(node, 1, Ov118_AiEnterDown); break;
        case 9: SetIndexedSlot(node, 1, Ov118_AiEnterDefeat); break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
