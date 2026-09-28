/* When ready (+0x50 == 1) forward the handle at +0x214 to Ov245_SetSubStateByteTo9 and return its
 * result; otherwise return param_1. */
extern int Ov245_SetSubStateByteTo9(int arg);
int Ov245_Mounted_ForceState9IfReady(int param_1) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov245_SetSubStateByteTo9(*(int *)(param_1 + 0x214));
    }
    return param_1;
}
