/* Tail-call Ov005_BlitResourceTilemap with flag 1. */
extern int Ov005_BlitResourceTilemap(int a, int b);
int Ov005_ResourceEntryCallback(int param_1) {
    return Ov005_BlitResourceTilemap(param_1, 1);
}
