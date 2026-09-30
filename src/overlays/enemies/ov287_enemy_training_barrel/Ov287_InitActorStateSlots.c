/* Init state: clears the current and pending actions, records the actor's velocity pointer, clears
 * bit 0 of the model's flag byte and the alpha, and installs the first action, the dispatcher and
 * the velocity step. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot();
extern void Ov287_SetHw60Bit15ClearSubBit0ThenAdvanceSlot(void);
extern void Ov287_DispatchSubStateByte(void);
extern void Ov287_StageVecUnlessState2ThenCommit(void);

void Ov287_InitActorStateSlots(int this_) {
    int holder = *(int *)(this_ + 4);
    *(signed char *)(*(int *)holder + 0x1c6) = 0;
    *(signed char *)(*(int *)holder + 0x1c7) = -1;
    *(int *)(holder + 0xc) = *(int *)holder + 0xb0;
    ((struct bf *)(*(int *)(*(int *)holder + 0x388) + 8))->b &= ~1;
    *(int *)(*(int *)holder + 0x394) = 0;
    SetIndexedSlot(this_, 1, (int)&Ov287_SetHw60Bit15ClearSubBit0ThenAdvanceSlot);
    SetIndexedSlot(this_, 0, (int)&Ov287_DispatchSubStateByte);
    SetIndexedSlot(this_, 2, (int)&Ov287_StageVecUnlessState2ThenCommit);
}
