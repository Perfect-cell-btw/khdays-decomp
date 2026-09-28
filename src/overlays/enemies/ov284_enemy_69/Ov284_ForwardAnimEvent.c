/* Starts the animation event on track 0 of the model subitem (+0x384). */

extern int SetSubitemState();

int Ov284_ForwardAnimEvent(int *r0, int r1, int r2) {
    return SetSubitemState(r0[0xE1], 0, (short)r1, r2);
}
