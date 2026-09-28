extern int SoundBank_Acquire(int a, int b);
extern int SoundBank_Release(int a, int b);

/* State 0 (and anything above 4) falls through the jump table to the shared
 * return, so it needs no case label. */
void Ov022_StepCueQueue(unsigned char *p) {
    switch (*p) {
    case 1:
    case 2:
        *p = 2;
        if (SoundBank_Acquire(*(signed char *)(p + 6), *(short *)(p + 2))) *p = 3;
        return;
    case 3:
        if (*(short *)(p + 2) != *(short *)(p + 4) && *(short *)(p + 4) != -1) *p = 4;
        return;
    case 4:
        if (SoundBank_Release(*(signed char *)(p + 6), *(short *)(p + 2)) == 0) return;
        *p = 1;
        *(short *)(p + 2) = *(short *)(p + 4);
        *(short *)(p + 4) = -1;
        return;
    }
}
