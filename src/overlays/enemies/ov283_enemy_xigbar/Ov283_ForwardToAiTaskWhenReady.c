/* When ready (+0x50 == 1) forward the handle at +0x214 and param_2 to Ov283_Item_Launch;
 * otherwise return param_1. */
extern int Ov283_Item_Launch(int a, int b);
int Ov283_ForwardToAiTaskWhenReady(int param_1, int param_2) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov283_Item_Launch(*(int *)(param_1 + 0x214), param_2);
    }
    return param_1;
}
