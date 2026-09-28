extern void ReleaseField74AndCleanup();extern void ReleaseField74AndCleanup();extern void Ov063_ReleaseChildArray8();
void Ov063_setupTriple(int p) {
    ReleaseField74AndCleanup(p + 0x18);
    ReleaseField74AndCleanup(p + 0x128);
    Ov063_ReleaseChildArray8(p);
}
