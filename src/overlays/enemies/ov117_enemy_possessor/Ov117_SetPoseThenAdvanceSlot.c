/* Set animation state 1 then dispatch via SetIndexedSlot with handler Ov117_KeepDistanceOrRetreat.
 */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov117_KeepDistanceOrRetreat();

void Ov117_SetPoseThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 1, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov117_KeepDistanceOrRetreat);
}
