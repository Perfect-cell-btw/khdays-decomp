/* Advances the effect's pose state: idle or finished effects restart (timers cleared, state 1); in
 * state 3 binds tracks 0 and 2 to the follow-up animation and moves to state 4. */

extern void BindAnimTrack(int a, int b, int c, int d);

void Ov049_AdvancePoseState(int a, char *node) {
    signed char st = node[0];
    if (st == 0 || st == 5 || st == 6) {
        *(int *)(node + 0x110) = 0;
        *(int *)(node + 0x114) = 0;
        node[0] = 1;
        return;
    }
    if (st != 3) return;
    BindAnimTrack((int)(node + 4), 0, *(int *)(node + 0x10c), 3);
    BindAnimTrack((int)(node + 4), 2, *(int *)(node + 0x10c), 3);
    node[0] = 4;
}
