/* Tail-call Ov006_BlitCellBufferRegion with flag 1. */
extern int Ov006_BlitCellBufferRegion(int a, int b);
int Ov006_CopyCellBufferRegion(int param_1) {
    return Ov006_BlitCellBufferRegion(param_1, 1);
}
