/* Walks the object's entry list (count at +0x19, 0x1c8-byte entries at +0xc) and calls, for every
 * entry with a non-zero type byte (+2), that type's handler from the overlay's handler table. */

extern void (*data_ov039_020b5568[])();
void Ov039_dispatchEntryList(int param_1, int param_2) {
    int i = 0;
    if ((int)*(unsigned char *)(param_1 + 0x19) <= 0) return;
    {
        int off = 0;
        do {
            int e = *(int *)(param_1 + 0xc) + off;
            int t = *(signed char *)(e + 2);
            if (t != 0) data_ov039_020b5568[t](param_1, e, param_2);
            i++;
            off += 0x1c8;
        } while (i < (int)*(unsigned char *)(param_1 + 0x19));
    }
}
