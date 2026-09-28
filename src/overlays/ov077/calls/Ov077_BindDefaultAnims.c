/* Marks the first scene sequence active and binds animation tracks 0 and 2 to their default frames.
 */

extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov077_BindDefaultAnims(int a, int obj) {
    *(int *)(obj + 0xc) = 1;
    BindAnimTrack(obj + 0x10, 0, obj + 0xf0, 0);
    BindAnimTrack(obj + 0x10, 2, obj + 0xf0, 0);
    Anim_SetFrameWrapped(obj + 0x10, 0, 0);
    Anim_SetFrameWrapped(obj + 0x10, 2, 0);
}
