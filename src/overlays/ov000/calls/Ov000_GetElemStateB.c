/* Ov000_GetElemStateB -- look up a logo element by id, ov000. Maps id->slot
 * (Ov000_ElemIdToSlot_2); when valid, returns table[slot] from *data_ov000_0205ac28.
 * Always publishes the resolved slot through the optional out pointer. */
extern int Ov000_ElemIdToSlot_2(int id);
extern int *data_ov000_0205ac28;
int Ov000_GetElemStateB(int id, int *out) {
    int slot = Ov000_ElemIdToSlot_2(id);
    int result = 0;
    if (slot != -1) {
        result = data_ov000_0205ac28[slot];
    }
    if (out != 0) {
        *out = slot;
    }
    return result;
}
