/* NitroSystem: unpacks an NFTR font file into the font (NNSi_G2dGetUnpackedFont) and installs the
 * UTF-16 character splitter (NNSG2dFont: pRes, cbCharSpliter). */

extern void NNSi_G2dGetUnpackedFont(void *pNftrFile, void *pFont);
extern void NNSi_G2dSplitCharUTF16(void);

void NNS_G2dFontInitUTF16(int *pFont, void *pNftrFile) {
    NNSi_G2dGetUnpackedFont(pNftrFile, pFont);
    pFont[1] = (int)NNSi_G2dSplitCharUTF16;
}
