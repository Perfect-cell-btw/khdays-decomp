extern void ReleaseField74AndCleanup(int);

void Render_ReleaseItemOnce(int *param_1) {
    if ((*param_1 & 0x20) == 0) {
        ReleaseField74AndCleanup((int)param_1 + 4);
    }
    *param_1 |= 0x20;
}
