/* Starts an animation on the child selector through the shared framework (Ov107_StartAnim). */

extern int Ov107_StartAnim();

int Ov229_startAnim(int *r0, int r1) {
    return Ov107_StartAnim(((int **)r0)[0x490 / 4], r1, 1);
}
