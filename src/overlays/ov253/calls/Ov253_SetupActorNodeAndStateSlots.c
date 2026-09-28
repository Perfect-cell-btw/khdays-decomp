extern void SetIndexedSlot();
extern void Ov253_stSetDispFlags82(void);
extern void Ov253_SubStateDispatchC(void);
extern void Ov253_EaseTowardTarget(void);

void Ov253_SetupActorNodeAndStateSlots(int this_) {
    int holder = *(int *)(this_ + 4);
    *(signed char *)(*(int *)holder + 0x1c6) = 0;
    *(signed char *)(*(int *)holder + 0x1c7) = -1;
    *(int *)(holder + 4) = *(int *)holder + 0xb0;
    *(int *)(holder + 8) = *(int *)(*(int *)holder + 0x38c) + 0xad;
    {
        unsigned short *p = (unsigned short *)(*(int *)holder + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x16) << 0x18) >> 0x10));
    }
    SetIndexedSlot(this_, 1, (int)&Ov253_stSetDispFlags82);
    SetIndexedSlot(this_, 0, (int)&Ov253_SubStateDispatchC);
    SetIndexedSlot(this_, 2, (int)&Ov253_EaseTowardTarget);
}
