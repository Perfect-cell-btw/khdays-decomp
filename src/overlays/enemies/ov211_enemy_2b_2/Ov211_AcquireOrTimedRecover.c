/*
 * Ov211_AcquireOrTimedRecover -- x3 (ov210/211/282). AI-state tick: acquire target, else enter a timed
 * recovery.
 * Acquire (020cab14) -> state[4]; none -> mark *state[0]+0x1c7=2 and bail (0203c634 cb=0). Else fire
 * attack 0x12, set the timer state[0x14]=0x3000, pick a random heading state[0xc]=RandNextScaled(
 * 0x1001)+0x1000, clear state[0xb], and hand off to the 020d2b60 state.
 */
extern int  Ov107_FindNearestObject(int obj, int flag);
extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int  RandNextScaled(int mul);
extern void Ov211_StrafeSameTarget(void);

void Ov211_AcquireOrTimedRecover(int *self) {
    int *state = (int *)self[1];
    int target = Ov107_FindNearestObject(*state, 0);
    state[4] = target;
    if (target == 0) {
        *(char *)(*state + 0x1c7) = 2;
        SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), 0);
        return;
    }
    Ov107_PostTagUpdate(*state, 0x12, 0);
    state[0x14] = 0x3000;
    state[0xc] = RandNextScaled(0x1001) + 0x1000;
    state[0xb] = 0;
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), (int)&Ov211_StrafeSameTarget);
}
