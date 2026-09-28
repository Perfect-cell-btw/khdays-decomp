/* Invoke the tag-tracker's callback at +0x3c with the given argument, if one is installed.
 * Ov025_TagTracker_InvokeCallback is the byte-identical ov025 copy. */

void Ov002_TagTracker_InvokeCallback(int *r0, int r1) {
    void (*fp)(int) = (void (*)(int))r0[0xf];
    if (fp == 0) {
        return;
    }
    fp(r1);
}
