/* Releases the three animation sub-blocks of this overlay's shared battle object. */

extern void ReleaseField74AndCleanup();
extern int data_ov040_020b4b20;
void Ov040_ReleaseThreeSubBlocks2c50(void)
{
    int base = data_ov040_020b4b20 + 0x2c50;
    ReleaseField74AndCleanup(base + 0xc);
    ReleaseField74AndCleanup(base + 0x128);
    ReleaseField74AndCleanup(base + 0x238);
}
