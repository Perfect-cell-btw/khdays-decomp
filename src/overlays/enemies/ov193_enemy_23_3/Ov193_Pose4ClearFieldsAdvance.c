/* State step: posts pose 4, clears the timer and the leap flags and installs the leap step. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov193_LeapTick();

void Ov193_Pose4ClearFieldsAdvance(int this_) {
    int n = *(int *)(this_ + 4);
    Ov107_PostTagUpdate(*(int *)n, 4, 0);
    *(int *)(n + 0x2c) = 0;
    *(char *)(n + 0x38) = 0;
    *(unsigned char *)(n + 0x39) &= ~2;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov193_LeapTick);
}
