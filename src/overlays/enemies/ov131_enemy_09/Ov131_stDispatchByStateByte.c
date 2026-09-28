extern void SetIndexedSlot(int, int, void *);
extern void Ov131_stateSetFlagsClearBit(void);
extern void Ov131_Action48Callback(void);
extern void Ov131_stDiv30Store(void);
extern void Ov131_stDiv30Store_2(void);
extern void Ov131_PickRandomSpinDirection(void);
extern void Ov131_stateAnimAimAtTarget(void);
extern void Ov131_stateSetFlagEffect(void);
extern void Ov131_SetPose6ThenAdvanceSlot(void);
extern void Ov131_ThrowRelease_Enter(void);
extern void Ov131_ConfigHw60FlagsBeginAction4a(void);
extern void Ov131_stateToggleFlagsEffectClear(void);

struct node60 { unsigned short lo : 8; unsigned short hi : 8; };
struct flagword { unsigned f8 : 8; };

void Ov131_stDispatchByStateByte(int param_1) {
    int *node = *(int **)(param_1 + 4);
    int obj = *node;

    if (*(char *)(obj + 0x1c7) != -1) {
        ((struct node60 *)(obj + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*node + 0x1ae) &= ~1;
        ((struct flagword *)(*(int *)(*node + 0x388) + 8))->f8 |= 1;
        *(char *)(*node + 0x1c6) = *(char *)(*node + 0x1c7);
        switch (*(char *)(*node + 0x1c6)) {
        case 0:  SetIndexedSlot(param_1, 1, Ov131_stateSetFlagsClearBit); break;
        case 1:  SetIndexedSlot(param_1, 1, Ov131_Action48Callback); break;
        case 2:  SetIndexedSlot(param_1, 1, Ov131_stDiv30Store); break;
        case 4:  SetIndexedSlot(param_1, 1, Ov131_stDiv30Store_2); break;
        case 9:  SetIndexedSlot(param_1, 1, Ov131_PickRandomSpinDirection); break;
        case 5:  SetIndexedSlot(param_1, 1, Ov131_stateAnimAimAtTarget); break;
        case 6:  SetIndexedSlot(param_1, 1, Ov131_stateSetFlagEffect); break;
        case 7:  SetIndexedSlot(param_1, 1, Ov131_SetPose6ThenAdvanceSlot); break;
        case 8:  SetIndexedSlot(param_1, 1, Ov131_ThrowRelease_Enter); break;
        case 3:  SetIndexedSlot(param_1, 1, Ov131_ConfigHw60FlagsBeginAction4a); break;
        case 10: SetIndexedSlot(param_1, 1, Ov131_stateToggleFlagsEffectClear); break;
        }
    }
    *(char *)(*node + 0x1c7) = -1;
}
