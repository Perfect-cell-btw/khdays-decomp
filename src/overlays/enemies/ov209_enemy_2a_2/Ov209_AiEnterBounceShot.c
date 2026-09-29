/* Play the anim (ov107 mode 0xd,1), clear bit 0x40 in the high byte of the u16 flags at
 * *(child)+0x60, fire ov107_020c5af8(*child, 0x154, 0xb, *(child+0xc)), clear the +0x4e byte and
 * +0x2c, then register the handler. */
struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov209_BounceShotTick(int);
void Ov209_AiEnterBounceShot(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 0xd, 1);
    ((struct hw60 *)(*(int *)child + 0x60))->hi &= ~0x40;
    Ov107_BuildAndSendUpdate(*(int *)child, 0x154, 0xb, *(int *)(child + 0xc));
    *(signed char *)(child + 0x4e) = 0;
    *(int *)(child + 0x2c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov209_BounceShotTick);
}
