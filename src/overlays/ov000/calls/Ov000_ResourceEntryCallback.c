/* Tail-call Ov000_BlitOrClearMainTileRegion with flag 1. */
extern int Ov000_BlitOrClearMainTileRegion(int a, int b);
int Ov000_ResourceEntryCallback(int param_1) {
    return Ov000_BlitOrClearMainTileRegion(param_1, 1);
}
