/* Tail-call Ov000_BlitOrClearTileRegion with flag 1. */
extern int Ov000_BlitOrClearTileRegion(int a, int b);
int Ov000_ResourceEntryCallback_2(int param_1) {
    return Ov000_BlitOrClearTileRegion(param_1, 1);
}
