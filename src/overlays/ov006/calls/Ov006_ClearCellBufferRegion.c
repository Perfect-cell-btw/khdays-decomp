/* Tail-call Ov006_BlitCellBufferRegion with flag 0. */
extern int Ov006_BlitCellBufferRegion(int a, int b);
int Ov006_ClearCellBufferRegion(int param_1) {
    return Ov006_BlitCellBufferRegion(param_1, 0);
}
