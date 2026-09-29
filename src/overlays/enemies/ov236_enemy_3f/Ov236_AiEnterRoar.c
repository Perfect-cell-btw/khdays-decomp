/* Set bit0 of +0x1ae, clear bit0 of the +0x3a4->+8 byte, kick anim 5, arm the 0x127/7 timer with
 * +0x38, clear +0x28, clear bit0 of +0x3bc and dispatch 020d0900. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov236_RoarWaitTick(int);
struct b8 { unsigned f : 8; };
void Ov236_AiEnterRoar(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(unsigned short *)(*(int *)owner + 0x1ae) |= 1;
    ((struct b8 *)(*(int *)(*(int *)owner + 0x3a4) + 8))->f &= ~1;
    Ov107_PostTagUpdate(*(int *)owner, 5, 0);
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x127, 7, *(int *)(owner + 0x38));
    *(int *)(owner + 0x28) = 0;
    *(unsigned char *)(*(int *)owner + 0x3bc) &= ~1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov236_RoarWaitTick);
}
