extern void Ov094_StepCharge(int a, int b, int c);
extern void Ov094_UpdateTracksWhileActive(int a, int b, int c);
extern void Ov094_DriveSwingSequence(int a, int b, int c);
extern void Ov094_PlaceChargeEffect(int a, int b, int c);
extern void Ov094_TickChargeStateGuarded(int a, int b, int c);
extern int Session_GetLocalPlayerIndex(void);

void Ov094_UpdateAllPartsAndFlagLocal(int self, char *blk, int arg) {
    int any = 0;
    if (*(int *)(blk + 0x228) != 0) any = 1;
    Ov094_StepCharge(self, (int)(blk + 0x228), arg);
    Ov094_UpdateTracksWhileActive(self, (int)blk, arg);
    Ov094_DriveSwingSequence(self, (int)(blk + 0x118), arg);
    Ov094_PlaceChargeEffect(self, (int)(blk + 0x338), arg);
    Ov094_TickChargeStateGuarded(self, (int)(blk + 0x44 + 0x400), arg);
    if (any == 0) return;
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() != 0) return;
    *(long long *)((char *)self + 0x46c) |= 0x10000;
}
