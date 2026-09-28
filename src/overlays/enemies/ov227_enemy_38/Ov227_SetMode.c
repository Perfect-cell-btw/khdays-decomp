/* Store the mode at +0x420 and set anim (1 if mode else 4); when idle (mode 0),
 * raise flag 0x40 in the high byte at +0x60 and run Ov227_startAnim; always
 * reset +0x418/+0x41c and mirror the state byte +0x1c6 into +0x424. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov227_startAnim(int a, int b);
void Ov227_SetMode(int param_1, int param_2) {
    *(int *)(param_1 + 0x420) = param_2;
    Ov107_PostTagUpdate(param_1, param_2 ? 1 : 4, 0);
    if (*(int *)(param_1 + 0x420) == 0) {
        unsigned short *p = (unsigned short *)(param_1 + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x40;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
        Ov227_startAnim(param_1, 0);
    }
    *(unsigned char *)(param_1 + 0x418) = 0;
    *(int *)(param_1 + 0x41c) = 0;
    *(signed char *)(param_1 + 0x424) = *(signed char *)(param_1 + 0x1c6);
}
