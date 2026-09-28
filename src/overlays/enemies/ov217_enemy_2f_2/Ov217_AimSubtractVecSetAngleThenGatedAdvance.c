extern int Ov107_FindNearestObject(int node, int flag);
extern int SetIndexedSlot();
extern int VEC_Subtract();
extern int VEC_Normalize();
extern int func_020050b4();
extern int Ov217_AiCountdownQueue6(int this_, int x);

void Ov217_AimSubtractVecSetAngleThenGatedAdvance(int this_) {
    int holder = *(int *)(this_ + 4);
    int local[3];
    int r;
    int r4;

    r = Ov107_FindNearestObject(*(int *)holder, 0);
    *(int *)(holder + 8) = r;
    if (r == 0) {
        *(signed char *)(*(int *)holder + 0x1c7) = 2;
        SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
        return;
    }

    VEC_Subtract(r + 0x190, *(int *)holder + 0xb0, local);
    r4 = VEC_Normalize(local, local);
    *(int *)(holder + 0x4c) = func_020050b4(local[0], local[2]);

    if (Ov217_AiCountdownQueue6(this_, r4) != 0) {
        SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
        return;
    }
    *(signed char *)(*(int *)holder + 0x1c7) = 4;
}
