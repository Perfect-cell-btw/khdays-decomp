/* Reset the +0x2d34 request pair (byte 0 cleared, bit 1 of byte 1 cleared), then bind the
 * gOv062XemnasEfRgPackPath script on the +0x2c2c block at a rate of the +9 level plus 7. */
extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern int gOv062XemnasEfRgPackPath;

void Ov062_ResetScriptRequest(int this_) {
    unsigned char *r = (unsigned char *)(this_ + 0x2c2c);
    r[0x108] = 0;
    r[0x109] &= ~2;
    RegisterSeqAndInit((int)r, (int)&gOv062XemnasEfRgPackPath, 1, *(unsigned char *)(this_ + 9) + 7);
}
