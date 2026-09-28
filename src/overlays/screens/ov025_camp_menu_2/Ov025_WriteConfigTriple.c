extern void Tween_Sample();
extern void Ov025_MenuCursor_UpdateShadowProj();
extern void Camera_CommitMatrices();

void Ov025_WriteConfigTriple(int arg0) {
    Tween_Sample((void *)(arg0 + 0x11f4), (int *)(arg0 + 0x18));
    Tween_Sample((void *)(arg0 + 0x1210), (int *)(arg0 + 0x1c));
    Tween_Sample((void *)(arg0 + 0x122c), (int *)(arg0 + 0x20));
    Ov025_MenuCursor_UpdateShadowProj(arg0);
    Camera_CommitMatrices((void *)(arg0 + 4));
}
