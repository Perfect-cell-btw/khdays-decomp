/* Ov000_GetElemState -- look up a logo element state by id, ov000. Maps id->slot
 * (Ov000_ElemIdToSlot); when valid, returns the state word from the scene block
 * (*data_ov000_0205ac24, @+slot*4+0x4aec). Publishes the slot via the out pointer. */
extern int Ov000_ElemIdToSlot(int id);
extern char *data_ov000_0205ac24;
int Ov000_GetElemState(int id, int *out) {
    int slot = Ov000_ElemIdToSlot(id);
    int result = 0;
    if (slot != -1) {
        result = *(int *)(data_ov000_0205ac24 + slot * 4 + 0x4aec);
    }
    if (out != 0) {
        *out = slot;
    }
    return result;
}
