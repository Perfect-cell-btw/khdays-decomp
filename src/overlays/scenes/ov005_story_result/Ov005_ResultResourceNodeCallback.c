/* Resource callback: blits the result screen's tilemap for the entry. */

extern int Ov005_BlitResultTilemap(int a, int b);
int Ov005_ResultResourceNodeCallback(int param_1) {
    return Ov005_BlitResultTilemap(param_1, 0);
}
