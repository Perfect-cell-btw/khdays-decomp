/* Guarded tail-call: 0 when param_1 is null, else Ov024_Get80or100ByField28(param_1). */
extern int Ov024_Get80or100ByField28(int arg);
int Ov024_GetBlockSizeIfSet(int param_1) {
    if (param_1 == 0) return 0;
    return Ov024_Get80or100ByField28(param_1);
}
