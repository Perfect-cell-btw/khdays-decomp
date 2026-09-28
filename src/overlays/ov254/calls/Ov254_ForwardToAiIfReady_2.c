/* When ready (+0x50 == 1) forward the handle at +0x214 to Ov254_SetSubStateByte2IfEitherIs1 and return its
 * result; otherwise return param_1. */
extern int Ov254_SetSubStateByte2IfEitherIs1(int arg);
int Ov254_ForwardToAiIfReady_2(int param_1) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov254_SetSubStateByte2IfEitherIs1(*(int *)(param_1 + 0x214));
    }
    return param_1;
}
