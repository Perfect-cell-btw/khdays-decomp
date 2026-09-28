extern int Ov002_BlitTileRegion();
extern int Ov002_Compute_a_2b_2cd();

int Ov002_UiBlitTilesA(int arg0) {
    return Ov002_BlitTileRegion(arg0, Ov002_Compute_a_2b_2cd, 1);
}
