/* Store the mode at +0x408 and set anim (1 if mode else 4); when idle (mode 0),
 * raise flag 0x40 in the high byte at +0x60 and run Ov224_startAnim; always
 * reset +0x400/+0x404 and mirror the state byte +0x1c6 into +0x40c. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov224_startAnim(int a, int b);
void Ov224_SetModeAndResetCounters(int param_1, int param_2) {
    *(int *)(param_1 + 0x408) = param_2;
    Ov107_PostTagUpdate(param_1, param_2 ? 1 : 4, 0);
    if (*(int *)(param_1 + 0x408) == 0) {
        unsigned short *p = (unsigned short *)(param_1 + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x40;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
        Ov224_startAnim(param_1, 0);
    }
    *(unsigned char *)(param_1 + 0x400) = 0;
    *(int *)(param_1 + 0x404) = 0;
    *(signed char *)(param_1 + 0x40c) = *(signed char *)(param_1 + 0x1c6);
}
