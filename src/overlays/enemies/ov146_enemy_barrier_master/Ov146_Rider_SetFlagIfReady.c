/* When ready (+0x50 == 1) forward the handle at +0x214 and param_2 to Ov146_Rider_SetFlag;
 * otherwise return param_1. */
extern int Ov146_Rider_SetFlag(int a, int b);
int Ov146_Rider_SetFlagIfReady(int param_1, int param_2) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov146_Rider_SetFlag(*(int *)(param_1 + 0x214), param_2);
    }
    return param_1;
}
