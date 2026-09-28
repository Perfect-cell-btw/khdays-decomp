/* Binds animation tracks 0 and 2 of the sub-object to its animation set and moves both to the given
 * frame. */

extern void BindAnimTrack(int a, int b, int c, short d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov070_configTwoChannelsPair(int param_1, int param_2, int param_3) {
    BindAnimTrack(param_1 + 8, 0, param_1 + 0xe8, param_2);
    BindAnimTrack(param_1 + 8, 2, param_1 + 0xe8, param_2);
    Anim_SetFrameWrapped(param_1 + 8, 0, param_3);
    Anim_SetFrameWrapped(param_1 + 8, 2, param_3);
}
