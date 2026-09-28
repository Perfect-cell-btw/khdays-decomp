extern void Render_ReleaseNodeItem(int arg0);
extern void ReleaseField74AndCleanup(int arg0);

void Ov002_TeardownWidget(int self) {
    int owner = *(int *)(self + 8);

    Render_ReleaseNodeItem(self + 0x2c);
    if (*(signed char *)(owner + 0x58) != 0) {
        ReleaseField74AndCleanup(self + 0x1b0);
    }
    *(unsigned short *)(self + 0x12) &= ~4;
}
