/* Tile source for Ov002_UiBlitTilesB: returns the UI context address +0x12. */

extern int data_ov002_0207f60c;

int Ov002_UiTileSourceB(void) {
    return *(int *)&data_ov002_0207f60c + 0x12;
}
