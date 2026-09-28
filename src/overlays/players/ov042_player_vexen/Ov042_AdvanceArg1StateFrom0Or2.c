/* Moves an idle (0) or finished (2) effect to state 1, binding the rig first when it was idle. */

extern void Ov042_BindRig();

void Ov042_AdvanceArg1StateFrom0Or2(int this_, int *arg1) {
    int s = *arg1;
    if (s != 0 && s != 2) return;
    if (s == 0) {
        Ov042_BindRig(this_);
    }
    *arg1 = 1;
}
