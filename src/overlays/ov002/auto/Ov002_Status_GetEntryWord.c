/* Word +0x7c of 0x18-byte status entry idx. */

extern int data_ov002_0207f618;

int Ov002_Status_GetEntryWord(int arg0) {
    return *(int *)(*(int *)&data_ov002_0207f618 + arg0 * 0x18 + 0x7c);
}
