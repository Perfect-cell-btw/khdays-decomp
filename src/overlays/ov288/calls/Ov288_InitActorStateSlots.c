struct bf { unsigned b : 8; };
extern void SetIndexedSlot();
extern void Ov288_SetHw60Bit15ClearSubBit0ThenAdvanceSlot(void);
extern void Ov288_DispatchSubStateByte(void);
extern void Ov288_StageVecUnlessState2ThenCommit(void);

void Ov288_InitActorStateSlots(int this_) {
    int holder = *(int *)(this_ + 4);
    *(signed char *)(*(int *)holder + 0x1c6) = 0;
    *(signed char *)(*(int *)holder + 0x1c7) = -1;
    *(int *)(holder + 0xc) = *(int *)holder + 0xb0;
    ((struct bf *)(*(int *)(*(int *)holder + 0x388) + 8))->b &= ~1;
    *(int *)(*(int *)holder + 0x394) = 0;
    SetIndexedSlot(this_, 1, (int)&Ov288_SetHw60Bit15ClearSubBit0ThenAdvanceSlot);
    SetIndexedSlot(this_, 0, (int)&Ov288_DispatchSubStateByte);
    SetIndexedSlot(this_, 2, (int)&Ov288_StageVecUnlessState2ThenCommit);
}
