/* Emit the +0x4c and +0x68 spline pair from the a/b vectors, then finalize both. */
extern int Ov025_ApplyFirstValidSlot(int, int *);
extern void Tween_Configure(int dst, int mode, int a, int b, int extra);
extern void Tween_Start(int dst);
void Ov025_EmitSplinePair(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    int *va = (int *)param_4;
    int *vb = (int *)param_5;
    if (param_4 == 0) va = (int *)Ov025_ApplyFirstValidSlot(param_1, param_2);
    Tween_Configure(param_2 + 0x4c, param_3, va[0], vb[0], param_6);
    Tween_Configure(param_2 + 0x68, param_3, va[1], vb[1], param_6);
    Tween_Start(param_2 + 0x4c);
    Tween_Start(param_2 + 0x68);
}
