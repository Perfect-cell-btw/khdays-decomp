/* Zero the 0x1c-byte Tween and leave it in the cleared state: flag bits 0 and 1 off, bit 2 on. Used
 * by constructors on a Tween that has never run -- Ov000_InitSubsystemObject does this to the one
 * embedded at +0x4a54. */

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned int size);

struct X {
    char _0[0x18];
    unsigned int flags;
};

void Tween_Clear(struct X *p) {
    MI_CpuFill8(p, 0, 0x1c);
    p->flags &= ~1;
    p->flags &= ~2;
    p->flags |= 4;
}
