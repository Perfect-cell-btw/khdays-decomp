/* Tail-call Ov005_BlitResultTilemap with flag 1. */
extern int Ov005_BlitResultTilemap(int a, int b);
int Ov005_ResultResourceEntryCallback(int param_1) {
    return Ov005_BlitResultTilemap(param_1, 1);
}
