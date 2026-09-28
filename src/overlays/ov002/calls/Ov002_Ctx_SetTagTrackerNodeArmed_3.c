extern int data_ov002_0207f60c;
extern int Ov002_FillTilemapRegionPalette();

int Ov002_Ctx_SetTagTrackerNodeArmed_3(int arg0, int arg1) {
    return Ov002_FillTilemapRegionPalette(*(int *)&data_ov002_0207f60c + 0xdc, arg0, arg1);
}
