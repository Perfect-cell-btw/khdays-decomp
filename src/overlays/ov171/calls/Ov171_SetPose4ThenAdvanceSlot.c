/* Push animation params (4, 0) to the sprite, then dispatch via SetIndexedSlot with handler
 * Ov171_AiDecelUntilAnimEnd. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov171_AiDecelUntilAnimEnd();

void Ov171_SetPose4ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 4, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov171_AiDecelUntilAnimEnd);
}
