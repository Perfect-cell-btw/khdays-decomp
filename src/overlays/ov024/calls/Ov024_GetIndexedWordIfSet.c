/* Guarded tail-call: 0 when param_1 is null, else Ov024_GetIndexedWordAt0x88(param_1). */
extern int Ov024_GetIndexedWordAt0x88(int arg);
int Ov024_GetIndexedWordIfSet(int param_1) {
    if (param_1 == 0) return 0;
    return Ov024_GetIndexedWordAt0x88(param_1);
}
