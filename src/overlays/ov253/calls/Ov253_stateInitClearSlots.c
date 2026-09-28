/* Initialise a spawned child: point its +4 at obj+0xb0, reset state bytes
 * +0x1c6/+0x1c7, clear the low bit of its high-byte flags at +0x60 and of the u16
 * at +0x1ae, then run the 0/1/2 dispatch sequence. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov253_AiDispatchPendingAction(void);
extern void Ov253_StopEnter(void);
extern void Ov253_PublishPoseAndReset(void);

struct hi_flags_020cec74 { unsigned short pad : 8; unsigned short flags : 8; };

void Ov253_stateInitClearSlots(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 4) = *(int *)child + 0xb0;
    *(signed char *)(*(int *)child + 0x1c6) = 0;
    *(signed char *)(*(int *)child + 0x1c7) = -1;
    ((struct hi_flags_020cec74 *)(*(int *)child + 0x60))->flags &= ~1;
    *(unsigned short *)(*(int *)child + 0x1ae) &= ~1;
    SetIndexedSlot(param_1, 0, (void *)&Ov253_AiDispatchPendingAction);
    SetIndexedSlot(param_1, 1, (void *)&Ov253_StopEnter);
    SetIndexedSlot(param_1, 2, (void *)&Ov253_PublishPoseAndReset);
}
