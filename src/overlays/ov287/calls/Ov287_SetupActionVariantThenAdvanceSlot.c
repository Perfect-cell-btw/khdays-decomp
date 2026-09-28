struct bf { unsigned b : 8; };
extern void Ov107_PostTagUpdate(int node, int a, int b);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot();
extern void Ov287_AreaSweepAttack_Tick(void);

void Ov287_SetupActionVariantThenAdvanceSlot(int this_) {
    int holder = *(int *)(this_ + 4);
    Ov107_PostTagUpdate(*(int *)holder, 3, 0);
    *(unsigned short *)(*(int *)holder + 0x1ae) |= 0x10;
    ((struct bf *)(*(int *)(*(int *)holder + 0x388) + 8))->b &= ~1;
    *(unsigned short *)(*(int *)holder + 0x1ae) |= 1;
    Ov107_BuildAndSendUpdate(*(int *)holder, 0x15b,
                        (unsigned short)(*(int *)(*(int *)holder + 0x38c) == 0 ? 4 : 5),
                        *(int *)(holder + 0xc));
    *(int *)(*(int *)holder + 0x394) = 0;
    *(int *)(holder + 0x34) = 0;
    *(int *)(holder + 0x4c) = 0;
    *(int *)(holder + 0x50) = 0;
    *(signed char *)(holder + 0x54) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov287_AreaSweepAttack_Tick);
}
