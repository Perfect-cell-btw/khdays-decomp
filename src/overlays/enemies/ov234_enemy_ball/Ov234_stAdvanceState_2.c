/* AI step: continues with the knockback slide. */

extern void SetIndexedSlot();
extern void Ov234_KnockbackSlide(void);
void Ov234_stAdvanceState_2(int node) {
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov234_KnockbackSlide);
}
