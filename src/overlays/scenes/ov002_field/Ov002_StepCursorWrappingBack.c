/* Step the wrap-around cursor BACKWARDS: (cursor + count - 1) modulo count, hand
 * the new index to Ov002_MoveCursorTo and play the move sound. Mirror of
 * Ov002_StepCursorWrapping. func_02020400 is the signed-divide helper and must be
 * called by address -- `%` emits _s32_div_f, which this project does not define. */
extern long long func_02020400(int a, int b);
extern void Ov002_MoveCursorTo(int index);
extern void PlaySound(int a, int b);

extern char *data_ov002_0207f624;

void Ov002_StepCursorWrappingBack(void) {
    char *ctx = data_ov002_0207f624;
    int count = *(int *)(ctx + 0x7e0);

    if (count <= 0) {
        return;
    }

    Ov002_MoveCursorTo((int)(func_02020400(*(int *)(ctx + 0x7dc) + count - 1, count) >> 0x20));
    PlaySound(0, 0);
}
