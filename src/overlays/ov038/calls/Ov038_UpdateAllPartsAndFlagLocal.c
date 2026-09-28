extern void Ov038_StepCharge(int a, int b, int c);
extern void Ov038_UpdateTracksWhileActive(int a, int b, int c);
extern void Ov038_DriveSwingSequence(int a, int b, int c);
extern void Ov038_PlaceChargeEffect(int a, int b, int c);
extern void Ov038_TickChargeStateGuarded(int a, int b, int c);
extern int Session_GetLocalPlayerIndex(void);

void Ov038_UpdateAllPartsAndFlagLocal(int self, char *blk, int arg) {
    int any = 0;
    if (*(int *)(blk + 0x228) != 0) any = 1;
    Ov038_StepCharge(self, (int)(blk + 0x228), arg);
    Ov038_UpdateTracksWhileActive(self, (int)blk, arg);
    Ov038_DriveSwingSequence(self, (int)(blk + 0x118), arg);
    Ov038_PlaceChargeEffect(self, (int)(blk + 0x338), arg);
    Ov038_TickChargeStateGuarded(self, (int)(blk + 0x44 + 0x400), arg);
    if (any == 0) return;
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() != 0) return;
    *(long long *)((char *)self + 0x46c) |= 0x10000;
}
