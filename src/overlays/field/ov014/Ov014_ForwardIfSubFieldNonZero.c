extern void ReleaseField74AndCleanup();

void Ov014_ForwardIfSubFieldNonZero(int this_) {
    if (*(signed char *)(*(int *)(this_ + 8) + 0x58) == 0) {
        return;
    }
    ReleaseField74AndCleanup(this_ + 0x2c);
}
