/* When ready (+0x50 == 1) forward the handle at +0x214 and param_2 to Ov254_Marker_PlayAnimAction;
 * otherwise return param_1. */
extern int Ov254_Marker_PlayAnimAction(int a, int b);
int Ov254_ForwardToAiTaskWhenReady(int param_1, int param_2) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov254_Marker_PlayAnimAction(*(int *)(param_1 + 0x214), param_2);
    }
    return param_1;
}
