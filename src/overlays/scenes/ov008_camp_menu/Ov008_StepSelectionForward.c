/* The single-case switch is deliberate: two plain `if (...) return;` guards let mwcc
 * if-convert the second into the first (ldreq/cmpeq, 4 B short). The ROM emits two
 * separate `popne {r3,pc}` early returns, and the switch is what reproduces that. */
extern void Ov008_PlaceElementByVariant(int obj, int old_value, int new_value);
extern void PlaySound(int a, int b);

void Ov008_StepSelectionForward(int param_1) {
    int old = *(int *)param_1;
    int nv;
    switch (*(int *)(param_1 + 0x23c)) {
    case 0:
        if (*(int *)(param_1 + 4) != 0) return;
        nv = old + 1;
        *(int *)param_1 = nv;
        if (nv >= 3) {
            *(int *)param_1 = 0;
        }
        Ov008_PlaceElementByVariant(param_1, old, *(int *)param_1);
        PlaySound(0, 0);
        break;
    }
}
