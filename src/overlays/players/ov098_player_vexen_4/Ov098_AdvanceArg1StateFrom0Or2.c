extern void Ov098_BindRig();

void Ov098_AdvanceArg1StateFrom0Or2(int this_, int *arg1) {
    int s = *arg1;
    if (s != 0 && s != 2) return;
    if (s == 0) {
        Ov098_BindRig(this_);
    }
    *arg1 = 1;
}
