extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov064_BindAnimsOnPoseReset(int a, char *node) {
    signed char st = node[0];
    if (st == 0 || st == 4 || st == 5) {
        BindAnimTrack((int)(node + 4), 0, (int)(node + 0xe4), 0);
        BindAnimTrack((int)(node + 4), 2, (int)(node + 0xe4), 0);
        Anim_SetFrameWrapped((int)(node + 4), 0, 0);
        Anim_SetFrameWrapped((int)(node + 4), 2, 0);
        *(int *)(node + 0x10c) = 0;
        *(int *)(node + 0x110) = 0;
        node[0] = 1;
    }
}
