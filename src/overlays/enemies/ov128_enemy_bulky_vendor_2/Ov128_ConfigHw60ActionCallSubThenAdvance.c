/* AI step: clears bit 0 and sets the stance bits in the high byte of the actor's flags (+0x60),
 * sets bits 0-1 of +0x1ae, clears bit 0 of its model's flag byte, sends a state update, fires an
 * effect on a random list entry, clears the pending action and clears the step handler. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void Ov128_FireEffectOnRandomListId(int this_);
extern void SetIndexedSlot();

void Ov128_ConfigHw60ActionCallSubThenAdvance(int this_) {
    int holder = *(int *)(this_ + 4);
    ((struct hw60 *)(*(int *)holder + 0x60))->hi &= ~1;
    *(unsigned short *)(*(int *)holder + 0x1ae) |= 3;
    {
        unsigned short *p = (unsigned short *)(*(int *)holder + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*(int *)holder + 0x388) + 8))->b &= ~1;
    Ov107_BuildAndSendUpdate(*(int *)holder, 0, 0x4a, *(int *)(holder + 0x14));
    Ov128_FireEffectOnRandomListId(this_);
    *(signed char *)(*(int *)holder + 0x1c7) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
