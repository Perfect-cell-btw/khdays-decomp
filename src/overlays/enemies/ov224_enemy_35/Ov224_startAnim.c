/* Starts an animation on the child selector through the shared framework (Ov107_StartAnim). */

extern int Ov107_StartAnim();

int Ov224_startAnim(int *r0, int r1)
{
    return Ov107_StartAnim(r0[0xff], r1, 0);
}
