/* When the sub-object is idle, binds its default animation tracks 0 and 2, rewinds them and marks
 * it active. */

extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov033_BindDefaultAnimsIfIdle(int a, int obj) {
    if (*(int *)obj != 0) return;
    BindAnimTrack(obj + 0xc, 0, obj + 0xec, 0);
    BindAnimTrack(obj + 0xc, 2, obj + 0xec, 0);
    Anim_SetFrameWrapped(obj + 0xc, 0, 0);
    Anim_SetFrameWrapped(obj + 0xc, 2, 0);
    *(int *)obj = 1;
}
