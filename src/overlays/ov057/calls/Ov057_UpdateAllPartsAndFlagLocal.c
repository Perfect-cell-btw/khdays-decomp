extern void Ov057_TickChargeSequence(int a, int b, int c);
extern void Ov057_UpdateTracksWhileActive(int a, int b, int c);
extern void Ov057_DriveSwingSequence(int a, int b, int c);
extern void Ov057_TickForwardEffectSequence(int a, int b, int c);
extern void Ov057_TickChargeStateGuarded(int a, int b, int c);
extern int Session_GetLocalPlayerIndex(void);

void Ov057_UpdateAllPartsAndFlagLocal(int self, char *blk, int arg) {
    int any = 0;
    if (*(int *)(blk + 0x228) != 0) any = 1;
    Ov057_TickChargeSequence(self, (int)(blk + 0x228), arg);
    Ov057_UpdateTracksWhileActive(self, (int)blk, arg);
    Ov057_DriveSwingSequence(self, (int)(blk + 0x118), arg);
    Ov057_TickForwardEffectSequence(self, (int)(blk + 0x338), arg);
    Ov057_TickChargeStateGuarded(self, (int)(blk + 0x44 + 0x400), arg);
    if (any == 0) return;
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() != 0) return;
    *(long long *)((char *)self + 0x46c) |= 0x10000;
}
