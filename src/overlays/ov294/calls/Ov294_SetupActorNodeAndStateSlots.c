extern void SetIndexedSlot();
extern void Ov294_stSetDispFlagsde(void);
extern void Ov294_DispatchSubStateByte(void);
extern void Ov294_AiSlot2NoOp(void);

void Ov294_SetupActorNodeAndStateSlots(int this_) {
    int holder = *(int *)(this_ + 4);
    *(signed char *)(*(int *)holder + 0x1c6) = 0;
    *(signed char *)(*(int *)holder + 0x1c7) = -1;
    *(int *)(holder + 4) = *(int *)holder + 0xb0;
    *(int *)(holder + 8) = *(int *)(*(int *)holder + 0x384) + 0xad;
    {
        unsigned short *p = (unsigned short *)(*(int *)holder + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x1e) << 0x18) >> 0x10));
    }
    SetIndexedSlot(this_, 1, (int)&Ov294_stSetDispFlagsde);
    SetIndexedSlot(this_, 0, (int)&Ov294_DispatchSubStateByte);
    SetIndexedSlot(this_, 2, (int)&Ov294_AiSlot2NoOp);
}
