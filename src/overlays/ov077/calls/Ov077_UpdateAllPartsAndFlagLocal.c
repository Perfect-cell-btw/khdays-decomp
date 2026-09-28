extern void Ov077_UpdateChargeSequence(int a, int b, int c);
extern void Ov077_UpdateTracksWhileActive(int a, int b, int c);
extern void Ov077_DriveSwingSequence(int a, int b, int c);
extern void Ov077_UpdateChargeEmitter(int a, int b, int c);
extern void Ov077_TickChargeStateGuarded(int a, int b, int c);
extern int Session_GetLocalPlayerIndex(void);

void Ov077_UpdateAllPartsAndFlagLocal(int self, char *blk, int arg) {
    int any = 0;
    if (*(int *)(blk + 0x228) != 0) any = 1;
    Ov077_UpdateChargeSequence(self, (int)(blk + 0x228), arg);
    Ov077_UpdateTracksWhileActive(self, (int)blk, arg);
    Ov077_DriveSwingSequence(self, (int)(blk + 0x118), arg);
    Ov077_UpdateChargeEmitter(self, (int)(blk + 0x338), arg);
    Ov077_TickChargeStateGuarded(self, (int)(blk + 0x44 + 0x400), arg);
    if (any == 0) return;
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() != 0) return;
    *(long long *)((char *)self + 0x46c) |= 0x10000;
}
