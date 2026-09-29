/* Begins the special attack: picks the effect timing for the game mode, records the attack variant
 * and switches to state 0x21. */

extern int GetFrameRateMode(int p);
extern void Ov022_ActorSetState(int a, int b);
extern int data_ov055_020b7740;

void Ov055_InitStateFieldFromQuery(int this_, int arg1) {
    int p = data_ov055_020b7740 + 0x194;
    int base = p + 0x2c00;
    int r = GetFrameRateMode(p);
    *(int *)(base + 0x130) = (r == 1) ? 0x171 : 0xf6;
    *(int *)base = arg1;
    Ov022_ActorSetState(this_, 0x21);
}
