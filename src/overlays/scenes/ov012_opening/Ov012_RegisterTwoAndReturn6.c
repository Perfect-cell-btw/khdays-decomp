/* Script command: submits a movie request with two operands; returns 6. */

extern int ScriptVm_ReadOperandInt(void *a, int b);
extern void Ov012_SubmitRequestIfIdle(int x, int y);

int Ov012_RegisterTwoAndReturn6(void *a, int b) {
    int r1 = ScriptVm_ReadOperandInt(a, b);
    int r2 = ScriptVm_ReadOperandInt(a, b + 8);
    Ov012_SubmitRequestIfIdle(r1, r2);
    return 6;
}
