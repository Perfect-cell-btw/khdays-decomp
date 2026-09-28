/* UI setup entry 4: blits the tile region with Ov002_UiTileSourceB, mode 0. */

extern int Ov002_BlitTileRegion();
extern int Ov002_UiTileSourceB();

int Ov002_UiBlitTilesB(int arg0) {
    return Ov002_BlitTileRegion(arg0, Ov002_UiTileSourceB, 0);
}
