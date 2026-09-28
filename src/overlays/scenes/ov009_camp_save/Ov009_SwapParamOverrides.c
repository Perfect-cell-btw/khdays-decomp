/* Swaps the parameter overrides of the current element: restores the previous element's saved slot
 * values, applies the new element's override values and makes it current (+0x4a70). */

extern int SetSubitemValueFromIndex();

void Ov009_SwapParamOverrides(char *a, int *b)
{
    int i = 0;
    int *previous = *(int **)(a + 0x4a70);

    for (; i < 2; i++) {
        if (previous != 0) {
            if (previous[i + 5] != -1 && previous[i + 13] != -1) {
                SetSubitemValueFromIndex(a, previous[i + 5], previous[i + 13]);
            }
        }

        if (b != 0) {
            if (b[i + 5] != -1 && b[i + 15] != -1) {
                SetSubitemValueFromIndex(a, b[i + 5], b[i + 15]);
            }
        }

        *(int **)(a + 0x4a70) = b;
    }
}
