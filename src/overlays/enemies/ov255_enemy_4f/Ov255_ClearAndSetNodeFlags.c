/* AI step: adjusts the stance bits (0x9e), clears the model flag and continues with waiting for the
 * partner. */

extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov255_Partner_AiWaitActive(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct b8 { unsigned int f : 8; };

void Ov255_ClearAndSetNodeFlags(int *self) {
    int *s = (int *)self[1];
    ((struct hw60 *)(*s + 0x60))->hi &= ~1;
    ((struct hw60 *)(*s + 0x60))->hi |= (unsigned char)0x9e;
    ((struct b8 *)(*(int *)(*s + 0x38c) + 8))->f &= ~1;
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), (void *)&Ov255_Partner_AiWaitActive);
}
