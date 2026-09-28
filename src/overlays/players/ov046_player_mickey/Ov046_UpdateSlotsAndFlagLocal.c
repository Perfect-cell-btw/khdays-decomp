extern void Ov046_DriveChargeSequence(int a, char *b, int c);
extern int Ov046_TickStateReturnDone(int a, int b);
extern int Session_GetLocalPlayerIndex(void);

void Ov046_UpdateSlotsAndFlagLocal(int self, char *blk, int arg) {
    int i;
    int any = 0;
    char *p;
    if (*(int *)(blk + 0x110) != 0) any = 1;
    Ov046_DriveChargeSequence(self, blk, arg);
    for (i = 0, p = blk + 0x128; i < 6; i++, p += 0x120) {
        if (Ov046_TickStateReturnDone((int)p, arg) == 0) any = 1;
    }
    if (any == 0) return;
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() != 0) return;
    *(long long *)((char *)self + 0x46c) |= 0x10000;
}
