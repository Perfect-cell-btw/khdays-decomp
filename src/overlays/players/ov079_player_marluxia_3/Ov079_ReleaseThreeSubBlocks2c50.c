/* Releases the three animation sub-blocks of this overlay's shared battle object. */

extern void ReleaseField74AndCleanup();
extern int data_ov079_020b9a00;
void Ov079_ReleaseThreeSubBlocks2c50(void)
{
    int base = data_ov079_020b9a00 + 0x2c50;
    ReleaseField74AndCleanup(base + 0xc);
    ReleaseField74AndCleanup(base + 0x128);
    ReleaseField74AndCleanup(base + 0x238);
}
