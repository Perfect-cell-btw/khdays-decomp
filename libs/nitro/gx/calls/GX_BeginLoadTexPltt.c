/* Releases the texture-palette banks and records both the released mask and the base
 * address the slot table maps it to. */
extern int GX_ResetBankForTexPltt(void);
extern int data_0204470c[];
extern unsigned short data_02041418[];

void GX_BeginLoadTexPltt(void) {
    int mask = GX_ResetBankForTexPltt();
    data_0204470c[3] = mask;
    data_0204470c[2] = data_02041418[mask >> 4] << 12;
}
