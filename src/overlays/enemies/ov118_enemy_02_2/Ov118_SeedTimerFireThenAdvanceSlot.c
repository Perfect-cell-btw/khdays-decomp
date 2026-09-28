/* Seed state[10] with the owner's field at +0x2c scaled by 30/10 (the ROM's magic-divide idiom, so
 * the source really is *0x1e then /10), fire attack 1 via Ov107_PostTagUpdate, then chain the next
 * step with SetIndexedSlot. Byte-identical twin in ov118. Follows the tree's ...ThenAdvanceSlot
 * convention; retired from stDiv10Store_<addr>, which named only the division and embedded the
 * function's own address. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov118_AimAtTarget(void);
void Ov118_SeedTimerFireThenAdvanceSlot(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[10] = v / 10;
    Ov107_PostTagUpdate(*state, 1, 1);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov118_AimAtTarget);
}
