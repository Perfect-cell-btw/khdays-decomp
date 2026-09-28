/* Returns the first active entry (bit 1 of its flag byte) of the 0x30-byte entry array at +0x10
 * whose u16 tag matches, or the end of the array when none does. */

struct tagentry {
    unsigned short tag;
    unsigned char _pad[0x22];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
};

int Ov002_FindActiveEntryByTag(int param_1, unsigned int param_2)
{
    int i = 0;
    if (0 < *(int *)(param_1 + 0x34)) {
        int entry = *(int *)(param_1 + 0x10);
        int off = 0;
        do {
            if (((struct tagentry *)entry)->b1 == 1 &&
                param_2 == *(unsigned short *)(*(int *)(param_1 + 0x10) + off))
                break;
            i = i + 1;
            entry = entry + 0x30;
            off = off + 0x30;
        } while (i < *(int *)(param_1 + 0x34));
    }
    return i * 0x30 + *(int *)(param_1 + 0x10);
}
