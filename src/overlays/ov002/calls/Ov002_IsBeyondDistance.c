extern int VEC_Distance();

int Ov002_IsBeyondDistance(int arg0, int arg1, int arg2) {
    return arg1 <= VEC_Distance(arg0, arg2);
}
