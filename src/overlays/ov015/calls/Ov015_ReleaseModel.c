#pragma thumb on
extern void ReleaseField74AndCleanup(int this_);
extern void Render_ReleaseNodeItem(unsigned char *sub);

void Ov015_ReleaseModel(char *obj) {
    ReleaseField74AndCleanup((int)(obj + 0x61c));
    Render_ReleaseNodeItem((unsigned char *)(obj + 0x498));
    *(unsigned short *)(obj + 0x12) &= ~4;
}
