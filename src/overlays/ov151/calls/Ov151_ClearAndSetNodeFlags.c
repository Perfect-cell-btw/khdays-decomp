extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov151_CopyBlock394ThenAdvance(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct b8 { unsigned int f : 8; };

void Ov151_ClearAndSetNodeFlags(int *self) {
    int *s = (int *)self[1];
    ((struct hw60 *)(*s + 0x60))->hi &= ~1;
    ((struct hw60 *)(*s + 0x60))->hi |= (unsigned char)0x82;
    ((struct b8 *)(*(int *)(*s + 0x388) + 8))->f &= ~1;
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), (void *)&Ov151_CopyBlock394ThenAdvance);
}
