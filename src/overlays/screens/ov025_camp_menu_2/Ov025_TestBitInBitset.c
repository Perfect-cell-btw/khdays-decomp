/* Whether the item's bit is set in the menu's bitset (+0x1ba4). */

int Ov025_TestBitInBitset(char *base, int index) {
    int *arr = (int *)(base + 0x1ba4);
    return (arr[index / 32] & (1 << (index % 32))) != 0;
}
