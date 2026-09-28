extern void Render_ReleaseNodeItem();

void Ov021_RunSubActionTwiceClearFlag4(int this_) {
    int sub = *(int *)(this_ + 8);
    Render_ReleaseNodeItem(this_ + 0x2c);
    if (*(signed char *)(sub + 0x58) != 0) {
        Render_ReleaseNodeItem(this_ + 0x2c);
    }
    *(unsigned short *)(this_ + 0x12) &= ~4;
}
