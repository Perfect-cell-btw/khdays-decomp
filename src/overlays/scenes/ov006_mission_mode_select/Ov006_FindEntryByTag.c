/* Returns the first active entry (non-zero word at +0x14) of the 0x38-byte entry array at +0xc
 * whose u16 tag matches, or the end of the array when none does. */

int Ov006_FindEntryByTag(int param_1, unsigned int param_2)
{
    int i = 0;
    if (0 < *(int *)(param_1 + 0x30)) {
        int entry = *(int *)(param_1 + 0xc);
        int off = 0;
        do {
            if ((*(int *)(entry + 0x14) != 0) &&
                (param_2 == *(unsigned short *)(*(int *)(param_1 + 0xc) + off)))
                break;
            i = i + 1;
            entry = entry + 0x38;
            off = off + 0x38;
        } while (i < *(int *)(param_1 + 0x30));
    }
    return i * 0x38 + *(int *)(param_1 + 0xc);
}
