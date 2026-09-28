extern void ReleaseField74AndCleanup();
extern int data_ov048_020b4b80;
void Ov048_ReleaseThreeSubBlocks2c2c(void)
{
    int base = data_ov048_020b4b80 + 0x2c2c;
    ReleaseField74AndCleanup(base + 0x24c);
    ReleaseField74AndCleanup(base + 0xc);
    ReleaseField74AndCleanup(base + 0x120);
}
