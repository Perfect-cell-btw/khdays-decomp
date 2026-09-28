/* Set the u16 at (self)[idx*6]+0x290. */
void Ov107_StoreSlotEvent(int param_1, int param_2, short param_3) {
    *(short *)(param_1 + param_2 * 6 + 0x290) = param_3;
}
