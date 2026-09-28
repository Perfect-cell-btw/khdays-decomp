/* Requests the resource pairs of the field context's enabled entries (bits of +0x229c, 15 entries),
 * plus pair 0x19 in context modes 4 and 7. */

extern signed char Ov002_GetCtxModeByte(void);
extern void Res_RequestIdPair(int id);
extern int BitArray_TestBit(void *base, unsigned int bit);

extern int data_ov002_0207fa10;
extern unsigned char data_ov002_0207e610[];

void Ov002_EmitEntriesForSetBits(void) {
    char *ctx = *(char **)&data_ov002_0207fa10;
    int i;
    unsigned char *row;

    if (Ov002_GetCtxModeByte() == 7 || Ov002_GetCtxModeByte() == 4) {
        Res_RequestIdPair(0x19);
    }
    row = data_ov002_0207e610;
    for (i = 0; i <= 0xe; i++) {
        if (BitArray_TestBit(ctx + 0x229c, i) != 0) {
            Res_RequestIdPair(row[1]);
        }
        row += 3;
    }
}
