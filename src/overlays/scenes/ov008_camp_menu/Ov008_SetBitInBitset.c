/* Sets the item's bit in the menu's bitset (+0x1ba4), only in the modes that record it. */

void Ov008_SetBitInBitset(int arg0, int arg1) {
    if (*(int *)(arg0 + 0x10) != 2 && *(int *)(arg0 + 0x28) == 0) return;
    *(unsigned int *)(arg0 + 0x1ba4 + (arg1 / 32) * 4) |= 1 << (arg1 % 32);
}
