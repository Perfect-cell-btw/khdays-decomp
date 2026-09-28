/* Binds each of the five animation tracks to the selected animation and resets every frame to zero.
 */

extern int BindAnimTrack(int, unsigned short, int, short);
extern int Anim_SetFrameWrapped(int, unsigned short, int);

void Ov077_SetSequenceAnimation(int r0, int r1) {
    int i;
    for (i = 0; i < 5; i++) {
        BindAnimTrack(r0 + 4, i, r0 + 0xe4, (short)r1);
        Anim_SetFrameWrapped(r0 + 4, i, 0);
    }
}
