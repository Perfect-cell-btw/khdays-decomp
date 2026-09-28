/* Whether the actor's animation is within its last frames (at least two steps, more in the slow
 * mode). */

extern int Anim_GetFrame(unsigned short *arg0, int arg1);
extern int Anim_GetLengthQ12(unsigned short *arg0, int arg1);
extern int func_02023c40(void);

int func_ov022_020ad588(int param_1) {
    int v = 0;
    int lo = Anim_GetFrame((unsigned short *)(*(int *)(param_1 + 0x20) + 4), v);
    int hi = Anim_GetLengthQ12((unsigned short *)(*(int *)(param_1 + 0x20) + 4), v);
    int lim = (func_02023c40() == 1) ? 0x3000 : 0x2000;
    int dbl = (int)*(short *)(param_1 + 0x2aba) * 2;
    if (lim <= dbl) {
        lim = dbl;
    }
    if (lo > hi - lim) {
        v = 1;
    }
    return v;
}
