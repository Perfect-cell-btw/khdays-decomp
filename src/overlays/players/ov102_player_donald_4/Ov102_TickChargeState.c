extern void Sequence_UpdateTracks(int a, int b);

void Ov102_TickChargeState(int self, int *node, int dt) {
    if (node[4] != 0 && *(int *)(self + 0x6bc) != 0x31) {
        node[4] = 0;
    }
    switch (node[4]) {
    default:
        return;
    case 1: {
        int t = node[0x47] + dt;
        node[0x47] = t;
        if (t >= 0x12000) node[4] = 2;
        return;
    }
    case 2:
        Sequence_UpdateTracks((int)node + 0x14, dt);
        return;
    }
}
