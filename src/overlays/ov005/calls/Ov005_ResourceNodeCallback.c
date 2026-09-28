/* Tail-call Ov005_BlitResourceTilemap with flag 0. */
extern int Ov005_BlitResourceTilemap(int a, int b);
int Ov005_ResourceNodeCallback(int param_1) {
    return Ov005_BlitResourceTilemap(param_1, 0);
}
