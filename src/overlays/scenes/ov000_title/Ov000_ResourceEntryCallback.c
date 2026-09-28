/* Resource callback: blits or clears the main tile region for the entry. */

extern int Ov000_BlitOrClearMainTileRegion(int a, int b);
int Ov000_ResourceEntryCallback(int param_1) {
    return Ov000_BlitOrClearMainTileRegion(param_1, 1);
}
