/* Activates the effect and binds its default tracks 0 and 2, rewound. */

extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov038_BindDefaultAnimsAtBase(int a, int obj) {
    *(int *)(obj + 0) = 1;
    BindAnimTrack(obj + 4, 0, obj + 0xe4, 0);
    BindAnimTrack(obj + 4, 2, obj + 0xe4, 0);
    Anim_SetFrameWrapped(obj + 4, 0, 0);
    Anim_SetFrameWrapped(obj + 4, 2, 0);
}
