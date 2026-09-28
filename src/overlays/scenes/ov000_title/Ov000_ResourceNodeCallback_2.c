/* Resource callback: blits or clears the tile region for the entry. */

extern int Ov000_BlitOrClearTileRegion(int a, int b);
int Ov000_ResourceNodeCallback_2(int param_1) {
    return Ov000_BlitOrClearTileRegion(param_1, 0);
}
