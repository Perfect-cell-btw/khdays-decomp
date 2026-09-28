/* Whether two points are within the sum of the radii. */

extern int VEC_Distance();

int Ov002_IsWithinRadii(int arg0, int arg1, int arg2, int arg3) {
    return arg1 + arg3 >= VEC_Distance(arg0, arg2);
}
