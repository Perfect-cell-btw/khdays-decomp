/* Switches the object to an animation mode: records the mode, clears its timer, binds tracks 0 and
 * 2 to the object's animation set and rewinds them. */

extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov096_BindAnimsMode3(int a, int obj) {
    *(int *)(obj + 0x234) = 3;
    *(int *)(obj + 0x230) = 0;
    BindAnimTrack(obj + 0x238, 0, obj + 0x318, 2);
    BindAnimTrack(obj + 0x238, 2, obj + 0x318, 2);
    Anim_SetFrameWrapped(obj + 0x238, 0, 0);
    Anim_SetFrameWrapped(obj + 0x238, 2, 0);
}
