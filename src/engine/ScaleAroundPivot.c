/* Scales a value's distance from the pivot: pivot + (value - pivot) * scale (fx32). */

extern int FX_Mul();

int ScaleAroundPivot(int arg0, int arg1, int arg2) {
    return FX_Mul(arg1 - arg2, arg0) + arg2;
}
