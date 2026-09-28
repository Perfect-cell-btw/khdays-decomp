extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_StartAnim(int a, int b, int c);
extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov127_stateFixedAngleMatrix(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct b8 { unsigned int f : 8; };

void Ov127_SetFlagsAndAdvance(int *self) {
    int *s = (int *)self[1];
    *(unsigned short *)(*s + 0x100 + 0xae) |= 1;
    ((struct b8 *)(*(int *)(*s + 0x388) + 8))->f &= ~1;
    ((struct hw60 *)(*s + 0x60))->hi |= (unsigned char)0x40;
    Ov107_PostTagUpdate(*s, 7, 0);
    Ov107_StartAnim(*(int *)(*s + 0x390), 0, 0);
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), (void *)&Ov127_stateFixedAngleMatrix);
}
