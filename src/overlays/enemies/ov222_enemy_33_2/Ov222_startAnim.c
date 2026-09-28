extern int Ov107_StartAnim();

int Ov222_startAnim(int *r0, int r1)
{
    return Ov107_StartAnim(r0[0xff], r1, 0);
}
