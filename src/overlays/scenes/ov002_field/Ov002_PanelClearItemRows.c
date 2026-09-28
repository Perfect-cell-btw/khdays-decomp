/* Blank the twelve item rows of both panel resources, plus the extra row the
 * second resource keeps at +0x2c0. Each row is a 0x40-byte record and only the
 * leading 0x1c bytes are cleared. */
extern void MIi_CpuClear16(int nValue, void *pDest, int nSize);
extern void *Ov002_GetItemResource(int nResource);

void Ov002_PanelClearItemRows(void) {
    int i;
    char *pGrid = (char *)Ov002_GetItemResource(9);
    char *pItems = (char *)Ov002_GetItemResource(0xb);

    MIi_CpuClear16(0, pItems + 0x2c0, 0x1c);
    for (i = 0; i < 0xc; i++) {
        MIi_CpuClear16(0, pGrid + (i + 0xc) * 0x40, 0x1c);
        MIi_CpuClear16(0, pItems + (i + 0xc) * 0x40, 0x1c);
    }
}
