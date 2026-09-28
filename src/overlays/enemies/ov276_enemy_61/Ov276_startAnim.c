/* Starts an animation on the object's child selector through the shared framework
 * (Ov107_StartAnim). */

extern void *Ov107_StartAnim();
void *Ov276_startAnim(int p, int p2) {
    return Ov107_StartAnim(*(int *)(p + 0x470), p2, 1);
}
