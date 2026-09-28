/* State step: sets bit 0 of +0x1ae, clears bit 0 of the model's flag byte, sets bit 1 in the high
 * byte of the actor's flags, posts pose 5, clears the timer and installs the next step. */

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov183_GuardFieldCClearField1cAdvance_2(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct b8 { unsigned int f : 8; };

void Ov183_BeginState5AndClear(int *self) {
    int *s = (int *)self[1];
    *(unsigned short *)(*s + 0x100 + 0xae) |= 1;
    ((struct b8 *)(*(int *)(*s + 0x388) + 8))->f &= ~1;
    ((struct hw60 *)(*s + 0x60))->hi |= (unsigned char)2;
    Ov107_PostTagUpdate(*s, 5, 0);
    s[7] = 0;
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), (void *)&Ov183_GuardFieldCClearField1cAdvance_2);
}
