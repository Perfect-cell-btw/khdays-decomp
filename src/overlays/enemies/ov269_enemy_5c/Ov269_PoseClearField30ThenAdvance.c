/* State step: posts pose 2, clears the timer, starts the child selector's animation and installs
 * the chase step. */

extern void Ov107_PostTagUpdate();
extern void Ov107_StartAnim();
extern void SetIndexedSlot();
extern void Ov269_ChaseTick();

void Ov269_PoseClearField30ThenAdvance(int this_) {
    int node = *(int *)(this_ + 4);
    Ov107_PostTagUpdate(*(int *)node, 2, 1);
    *(int *)(node + 0x30) = 0;
    Ov107_StartAnim(*(int *)(*(int *)node + 0x3d0), 0, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov269_ChaseTick);
}
