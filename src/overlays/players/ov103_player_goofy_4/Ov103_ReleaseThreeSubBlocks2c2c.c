extern void ReleaseField74AndCleanup();
extern int data_ov103_020bc120;
void Ov103_ReleaseThreeSubBlocks2c2c(void)
{
    int base = data_ov103_020bc120 + 0x2c2c;
    ReleaseField74AndCleanup(base + 0x24c);
    ReleaseField74AndCleanup(base + 0xc);
    ReleaseField74AndCleanup(base + 0x120);
}
