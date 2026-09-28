/* When ready (+0x50 == 1) forward the handle at +0x214 and param_2 to Ov146_Mount_SetState;
 * otherwise return param_1. */
extern int Ov146_Mount_SetState(int a, int b);
int Ov146_Mount_SetStateIfReady(int param_1, int param_2) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov146_Mount_SetState(*(int *)(param_1 + 0x214), param_2);
    }
    return param_1;
}
