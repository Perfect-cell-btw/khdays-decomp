/* Puts the effect in mode 2 and binds its tracks 0, 2 and 1, rewound. */

extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov041_BindAnimsMode2(int obj) {
    *(int *)obj = 2;
    BindAnimTrack(obj + 4, 0, obj + 0xe4, 0);
    BindAnimTrack(obj + 4, 2, obj + 0xe4, 0);
    BindAnimTrack(obj + 4, 1, obj + 0xe4, 0);
    Anim_SetFrameWrapped(obj + 4, 0, 0);
    Anim_SetFrameWrapped(obj + 4, 2, 0);
    Anim_SetFrameWrapped(obj + 4, 1, 0);
}
