/* Advance +0x68 by the frame delta; when the +0x21a gauge has drained set +0x1ae bits0-1; once
 * +0x68 passes 0xaa0 (and +0xac bit1 is clear) set it and notify 020cd2c8; then unless busy anim 6. */
extern int Ov259_RefreshAim(int);
extern int Ov259_MapHeldItemKindToAnim(int, int);
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov259_GuardTick(int);
void Ov259_AiFinisherTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov259_RefreshAim(param_1);
    *(int *)(owner + 0x68) += *(int *)(*(int *)param_1 + 0x2c);
    if ((short)*(short *)(*(int *)owner + 0x21a) <= 0) {
        *(unsigned short *)(*(int *)owner + 0x1ae) |= 3;
    }
    int f = *(unsigned char *)(owner + 0xac);
    if ((f & 2) == 0) {
        if (*(int *)(owner + 0x68) >= 0xaa0) {
            *(unsigned char *)(owner + 0xac) = f | 2;
            Ov259_MapHeldItemKindToAnim(*(int *)owner, 3);
        }
    }
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 6, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov259_GuardTick);
}
