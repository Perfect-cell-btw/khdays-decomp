extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);
extern int Sequence_UpdateTracks(int a, int b);

void Ov054_TickTwoPhaseAnim(int a, int *node, int dt) {
    switch (node[0]) {
    default:
        return;
    case 1: {
        int t = node[0x43] + dt;
        node[0x43] = t;
        if (t < node[0x44]) return;
        BindAnimTrack((int)node + 4, 0, (int)node + 0xe4, 0);
        BindAnimTrack((int)node + 4, 2, (int)node + 0xe4, 0);
        Anim_SetFrameWrapped((int)node + 4, 0, 0);
        Anim_SetFrameWrapped((int)node + 4, 2, 0);
        node[0] = 2;
        node[0x43] = 0;
        return;
    }
    case 2:
        node[0x43] += dt;
        if (Sequence_UpdateTracks((int)node + 4, dt) != 0) {
            node[0] = 0;
        }
        return;
    }
}
