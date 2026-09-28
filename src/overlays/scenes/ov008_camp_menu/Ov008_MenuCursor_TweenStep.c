/* Ov008_MenuCursor_TweenStep -- advance the ov008 cursor tween one step, ov008.
 * Samples the three x/y/z interpolators (obj+0x11f4/0x1210/0x122c) into the live cursor
 * (obj+0x18/0x1c/0x20), refreshes the derived shadow/projection (Ov008_MenuCursor_UpdateShadowProj),
 * then flags the cursor object dirty (Camera_CommitMatrices on obj+4). */
extern void Tween_Sample(void *interp, int *out);
extern void Ov008_MenuCursor_UpdateShadowProj(int obj);
extern void Camera_CommitMatrices(void *node);

void Ov008_MenuCursor_TweenStep(int obj) {
    Tween_Sample((void *)(obj + 0x11f4), (int *)(obj + 0x18));
    Tween_Sample((void *)(obj + 0x1210), (int *)(obj + 0x1c));
    Tween_Sample((void *)(obj + 0x122c), (int *)(obj + 0x20));
    Ov008_MenuCursor_UpdateShadowProj(obj);
    Camera_CommitMatrices((void *)(obj + 4));
}
