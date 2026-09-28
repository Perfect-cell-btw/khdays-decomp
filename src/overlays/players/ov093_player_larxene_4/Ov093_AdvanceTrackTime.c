/* Keeps the effect's tracks in step with the character's animation: resets it outside the attack
 * states, and in the synced state moves tracks 0-2 to the character's frame minus 1.0. */

extern int Anim_GetFrame(int a, int b);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov093_AdvanceTrackTime(int self, char *blk) {
    int st = *(int *)(self + 0x6bc);
    int t;
    if (st != 0x2f && st != 0x30 && *(int *)(blk + 0x11c) != 0) {
        *(int *)(blk + 0x11c) = 0;
    }
    if (*(int *)(blk + 0x11c) != 2) return;
    t = Anim_GetFrame(*(int *)(self + 0x20) + 4, 0);
    if (t <= 0x1000) return;
    Anim_SetFrameWrapped((int)(blk + 0x120), 0, t - 0x1000);
    Anim_SetFrameWrapped((int)(blk + 0x120), 2, t - 0x1000);
    Anim_SetFrameWrapped((int)(blk + 0x120), 1, t - 0x1000);
}
