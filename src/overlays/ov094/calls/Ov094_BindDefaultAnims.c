/* Restores the default animation bindings for the ov094 actor. */

extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov094_BindDefaultAnims(int a, int obj) {
    *(int *)(obj + 0xc) = 1;
    BindAnimTrack(obj + 0x10, 0, obj + 0xf0, 0);
    BindAnimTrack(obj + 0x10, 2, obj + 0xf0, 0);
    Anim_SetFrameWrapped(obj + 0x10, 0, 0);
    Anim_SetFrameWrapped(obj + 0x10, 2, 0);
}
