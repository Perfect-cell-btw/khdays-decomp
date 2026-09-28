/* Charge effect state machine: waits through two timed phases, then plays its tracks to the end and
 * returns to idle. */

extern int Sequence_UpdateTracks(int a, int b);

void Ov036_TickChargeStates(int a, int *node, int dt) {
    switch (node[0]) {
    default:
        return;
    case 1: {
        int t = node[0x43] + dt;
        node[0x43] = t;
        if (t >= 0x3000) node[0] = 2;
        return;
    }
    case 2: {
        int t = node[0x43] + dt;
        node[0x43] = t;
        if (t >= 0xc000) node[0] = 3;
    }
    case 3:
        if (Sequence_UpdateTracks((int)node + 4, dt) != 0) {
            node[0x43] = 0;
            node[0] = 0;
        }
        return;
    }
}
