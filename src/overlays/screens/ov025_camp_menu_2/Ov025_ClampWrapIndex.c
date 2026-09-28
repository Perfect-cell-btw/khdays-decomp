/* Wraps an index into [min, max): below the minimum goes to max-1, at or past the maximum goes to
 * the minimum. */

int Ov025_ClampWrapIndex(int a, int b, int c) {
    if (a < b) {
        a = (short)(c - 1);
    }
    if (a >= c) {
        a = b;
    }
    return a;
}
