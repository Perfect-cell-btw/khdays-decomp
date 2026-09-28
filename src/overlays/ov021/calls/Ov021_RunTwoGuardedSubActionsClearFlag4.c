extern void ReleaseField74AndCleanup();
extern void Render_ReleaseNodeItem();

void Ov021_RunTwoGuardedSubActionsClearFlag4(int this_) {
    int sub = *(int *)(this_ + 8);
    if ((*(unsigned short *)(this_ + 0x12) & 4) == 0) return;
    if (*(signed char *)(sub + 0x58) != 0) {
        ReleaseField74AndCleanup(this_ + 0x1c);
    }
    if (*(signed char *)(sub + 0x68) != 0) {
        Render_ReleaseNodeItem(this_ + 0x124);
    }
    *(unsigned short *)(this_ + 0x12) &= ~4;
}
