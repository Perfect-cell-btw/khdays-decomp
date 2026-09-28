extern void *Ov107_StartAnim();
void *Ov276_startAnim(int p, int p2) {
    return Ov107_StartAnim(*(int *)(p + 0x470), p2, 1);
}
