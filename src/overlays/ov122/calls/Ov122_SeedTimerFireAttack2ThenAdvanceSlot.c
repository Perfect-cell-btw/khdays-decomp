/* Seed state[6] with the owner's field at +0x2c scaled by 30/10 (the ROM's magic-divide idiom),
 * fire attack 2 passing that same value, clear state[0x10], then chain the next step. Distinct from
 * SeedTimerFireThenAdvanceSlot (ov117/ov118), which seeds state[10], fires attack 1 with no value
 * argument and does not clear anything. Retired from stDiv10Store_<addr>, which named only the
 * division and embedded each copy's own address. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov122_ChargeTowardTarget_Step(void);
void Ov122_SeedTimerFireAttack2ThenAdvanceSlot(int *node) {
    int result = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    result = result / 10;
    state[6] = result;
    Ov107_PostTagUpdate(*state, 2, 1, result);
    state[16] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov122_ChargeTowardTarget_Step);
}
