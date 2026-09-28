/* Keeps the effect's tracks in step with the character's animation: resets it outside the attack
 * state, and in the synced state moves tracks 0-2 to the character's frame minus 1.0. */

extern int Anim_GetFrame(int a, int b);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov041_AdvanceTrackTime(int self, int *node) {
    int t;
    if (*(int *)(self + 0x6bc) != 0x30 && node[0] != 0) {
        node[0] = 0;
    }
    if (node[0] != 2) return;
    t = Anim_GetFrame(*(int *)(self + 0x20) + 4, 0);
    if (t <= 0x1000) return;
    Anim_SetFrameWrapped((int)node + 4, 0, t - 0x1000);
    Anim_SetFrameWrapped((int)node + 4, 2, t - 0x1000);
    Anim_SetFrameWrapped((int)node + 4, 1, t - 0x1000);
}
