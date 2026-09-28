/* Releases the three animation sub-blocks of this overlay's shared battle object. */

extern void ReleaseField74AndCleanup();
extern int data_ov067_020b7380;
void Ov067_ReleaseThreeSubBlocks2c2c(void)
{
    int base = data_ov067_020b7380 + 0x2c2c;
    ReleaseField74AndCleanup(base + 0x24c);
    ReleaseField74AndCleanup(base + 0xc);
    ReleaseField74AndCleanup(base + 0x120);
}
