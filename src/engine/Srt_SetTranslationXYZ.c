/* Sets an SRT's translation per axis and marks the transform as non-identity. */

void Srt_SetTranslationXYZ(void *pR0, int r1, int r2, int r3) {
    int *r0 = (int *)pR0;
    r0[4] = r1;
    r0[5] = r2;
    r0[6] = r3;
    ((unsigned char *)r0)[0x28] &= ~1;
}
