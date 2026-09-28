/* Releases the three animation sub-blocks of this overlay's shared battle object. */

extern void ReleaseField74AndCleanup();
extern int data_ov096_020bc0c0;
void Ov096_ReleaseThreeSubBlocks2c50(void)
{
    int base = data_ov096_020bc0c0 + 0x2c50;
    ReleaseField74AndCleanup(base + 0xc);
    ReleaseField74AndCleanup(base + 0x128);
    ReleaseField74AndCleanup(base + 0x238);
}
