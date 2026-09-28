extern int BindAnimTrack(int, unsigned short, int, short);
extern int Anim_SetFrameWrapped(int, unsigned short, int);

void Ov065_BindChargeTracks(int r0, int r1) {
    int i;
    for (i = 0; i < 5; i++) {
        BindAnimTrack(r0 + 4, i, r0 + 0xe4, (short)r1);
        Anim_SetFrameWrapped(r0 + 4, i, 0);
    }
}
