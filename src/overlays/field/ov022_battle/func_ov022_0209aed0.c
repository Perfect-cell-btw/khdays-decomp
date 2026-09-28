/* Releases the actor's three effect model instances. */

extern void ReleaseField74AndCleanup(int arg0);
void func_ov022_0209aed0(int arg0) {
    int i = 0;
    int e = arg0 + 0x278c;
    do {
        ReleaseField74AndCleanup(e);
        i++;
        e += 0x108;
    } while (i < 3);
}
