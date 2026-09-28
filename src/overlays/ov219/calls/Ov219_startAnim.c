extern void *Ov107_StartAnim();
void *Ov219_startAnim(int p, int p2) {
    return Ov107_StartAnim(*(int *)(p + 0x394), p2, 1);
}
