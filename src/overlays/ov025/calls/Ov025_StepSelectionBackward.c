/* Single-case switch: two plain `if (...) return;` guards get if-converted into one
 * predicated chain (ldreq/cmpeq); the ROM emits two separate popne. Same shape as
 * ov008 02068588/020685d0. */
extern void Ov025_PlaceElementByVariant(int *obj, int old, int now);
extern void PlaySound(int a, int b);

void Ov025_StepSelectionBackward(int *param_1) {
    int old = *param_1;
    switch (param_1[0x8f]) {
    case 0:
        if (param_1[1] != 0) return;
        {
            int now = old - 1;
            *param_1 = now;
            if (now < 0) {
                *param_1 = 2;
            }
            Ov025_PlaceElementByVariant(param_1, old, *param_1);
            PlaySound(0, 0);
        }
        break;
    }
}
