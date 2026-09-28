/* Tail-call Ov005_BlitResultTilemap with flag 0. */
extern int Ov005_BlitResultTilemap(int a, int b);
int Ov005_ResultResourceNodeCallback(int param_1) {
    return Ov005_BlitResultTilemap(param_1, 0);
}
