/* Charge effect step: drops it when the character leaves the charge states, starts it once the
 * charge time is long enough, and plays its tracks to the end before resetting the follow-up
 * sequence. */

extern int Sequence_UpdateTracks(int a, int b);
extern void Ov094_ResetSequenceState(int a, int b);
extern int data_ov094_020bc240;

void Ov094_TickChargeStateGuarded(int self, int *node, int dt) {
    char *blk = (char *)(*(int *)&data_ov094_020bc240 + 0x2c + 0x2c00);
    if (node[0] == 1) {
        int st = *(int *)(self + 0x6bc);
        if (st != 0x2f && st != 0x32) node[0] = 0;
    }
    switch (node[0]) {
    default:
        return;
    case 1:
        if (*(int *)(self + 0x7b0) >= 0x12000) node[0] = 2;
        return;
    case 2:
        if (Sequence_UpdateTracks((int)node + 4, dt) == 0) return;
        Ov094_ResetSequenceState(self, (int)(blk + 0x118));
        node[0] = 0;
        return;
    }
}
