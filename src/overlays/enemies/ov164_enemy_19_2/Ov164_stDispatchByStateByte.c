extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov164_stateSetFlagsClearBit(void);
extern void Ov164_Action48Callback(void);
extern void Ov164_stDiv30Store(void);
extern void Ov164_stDiv30Store_2(void);
extern void Ov164_AiEnterAim(void);
extern void Ov164_ComputeTargetDeltaThenAdvance(void);
extern void Ov164_stateSetFlagEffect(void);
extern void Ov164_SetPose6ThenAdvanceSlot(void);
extern void Ov164_BeginThrowRelease(void);
extern void Ov164_ConfigHw60NoResetBeginAction4a(void);
extern void Ov164_ConfigHw60Action49ThenAdvance(void);

struct node60 { unsigned short lo : 8, hi : 8; };
struct flagbyte { unsigned int b : 8; };

void Ov164_stDispatchByStateByte(int *node)
{
    int *state = (int *)node[1];
    int *obj = (int *)*state;

    if ((signed char)*((char *)obj + 0x100 + 0xc7) != -1) {
        ((struct node60 *)((char *)obj + 0x60))->hi &= ~0xce;

        *(unsigned short *)((char *)*(int *)state + 0x100 + 0xae) &= ~1;

        ((struct flagbyte *)((char *)*(int *)((char *)*(int *)state + 0x388) + 8))->b |= 1;

        {
            int *o = (int *)*state;
            *((signed char *)o + 0x1c6) = (signed char)*((char *)o + 0x100 + 0xc7);
        }

        switch ((signed char)*((char *)*(int *)state + 0x100 + 0xc6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov164_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov164_Action48Callback);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov164_stDiv30Store);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov164_stDiv30Store_2);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov164_AiEnterAim);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov164_ComputeTargetDeltaThenAdvance);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov164_stateSetFlagEffect);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov164_SetPose6ThenAdvanceSlot);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov164_BeginThrowRelease);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov164_ConfigHw60NoResetBeginAction4a);
            break;
        case 10:
            SetIndexedSlot(node, 1, Ov164_ConfigHw60Action49ThenAdvance);
            break;
        }
    }

    *((signed char *)*(int *)state + 0x1c7) = -1;
}
