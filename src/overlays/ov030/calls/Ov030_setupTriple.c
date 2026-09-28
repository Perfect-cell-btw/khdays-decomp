extern void ReleaseField74AndCleanup();extern void ReleaseField74AndCleanup();extern void Ov030_ReleaseChildArray8();
void Ov030_setupTriple(int p) {
    ReleaseField74AndCleanup(p + 0x18);
    ReleaseField74AndCleanup(p + 0x128);
    Ov030_ReleaseChildArray8(p);
}
