/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern void ReleaseField74AndCleanup();extern void ReleaseField74AndCleanup();extern void Ov082_ReleaseChildArray8();
void Ov082_setupTriple(int p) {
    ReleaseField74AndCleanup(p + 0x18);
    ReleaseField74AndCleanup(p + 0x128);
    Ov082_ReleaseChildArray8(p);
}
