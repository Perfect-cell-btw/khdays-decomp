/* When ready (+0x50 == 1) forward the handle at +0x214 to Ov254_SetByte1c7IfState1_3 and return its
 * result; otherwise return param_1. */
extern int Ov254_SetByte1c7IfState1_3(int arg);
int Ov254_ForwardToAiIfReady_9(int param_1) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov254_SetByte1c7IfState1_3(*(int *)(param_1 + 0x214));
    }
    return param_1;
}
