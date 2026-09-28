/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern void ReleaseField74AndCleanup();extern void ReleaseField74AndCleanup();extern void Ov099_ReleaseChildArray8();
void Ov099_setupTriple(int p) {
    ReleaseField74AndCleanup(p + 0x18);
    ReleaseField74AndCleanup(p + 0x128);
    Ov099_ReleaseChildArray8(p);
}
