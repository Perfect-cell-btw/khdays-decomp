/* When ready (+0x50 == 1) forward the handle at +0x214 to Ov258_ItemDrop and return its
 * result; otherwise return param_1. */
extern int Ov258_ItemDrop(int arg);
int Ov258_ForwardToAiTaskWhenReady(int param_1) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov258_ItemDrop(*(int *)(param_1 + 0x214));
    }
    return param_1;
}
