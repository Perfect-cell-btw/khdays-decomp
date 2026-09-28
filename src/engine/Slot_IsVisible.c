/* Whether a slot's visible bit (bit 2 of its flags) is set. */

int Slot_IsVisible(int base, int index) {
    return (((unsigned int *)(base + index * 0x8c))[0x7c / 4] << 0x1d) >> 0x1f;
}
