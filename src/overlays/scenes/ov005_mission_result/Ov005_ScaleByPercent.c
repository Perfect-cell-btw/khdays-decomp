/* Ov005_ScaleByPercent -- scale `a` by the percentage Ov005_RoundRewardPercent reports for `b`.
 * The `/ 100` is the signed magic-reciprocal divide (smull by 0x51eb851f, asr #5 plus the sign
 * fixup), which is what `/ 100` compiles to -- it is not a shift. */
extern unsigned short Ov005_RoundRewardPercent(int a);

int Ov005_ScaleByPercent(int a, int b) {
    return a * Ov005_RoundRewardPercent(b) / 100;
}
