/* Guarded tail-call: 0 when param_1 is null, else Ov024_GetWord18(param_1). */
extern int Ov024_GetWord18(int arg);
int Ov024_ReleaseIfSet_2(int param_1) {
    if (param_1 == 0) return 0;
    return Ov024_GetWord18(param_1);
}
