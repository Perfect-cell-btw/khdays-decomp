/* Ov008_MissionEnterPage2 -- enter menu page 2.
 * Resets the page's resource block at OBJ+8, reloads it from gOv008UiMltMltgpPath, rebuilds
 * layer 0 and layer 2, re-applies the current Mission Mode sub-state (OBJ+0x94f4) to the model and
 * the text, and starts the page-3 entry animation.
 *
 * PROVENANCE: byte-identical twin of Ov006_MissionEnterPage2 -- same code, this overlay's own
 * globals, propagated mechanically and verified byte-exact.
 * The scene-identity phrasing that came with the twin source (Mission Mode / char select /
 * ov025 panel) is the REP's, NOT established for ov008, so it was removed rather than
 * carried over. What IS measured: ov008's own strings include UI/mlt/res.p2 (the same pack
 * ov006 loads) plus UI/cm/*.p2 and ba/ch/*, so resource detail naming those is sound; the
 * scene label is not. The offsets and logic below are this function's -- the code is
 * byte-identical to the rep.
 */
extern void Ov008_SweepElements(int *block);
extern void Ov008_LoadLayoutResource(int block, int desc);
extern void Ov008_MissionRetargetCellByTag(int layer, int a, int b);
extern void Ov008_Menu_SetupSprites(int state);
extern void Ov008_MissionBuildScreenCells(int state);
extern void Ov008_MissionRequestStateChange(int anim, int a, int b, int c, int d);
extern int *data_ov008_02090fa4;
extern int  gOv008UiMltMltgpPath;

void Ov008_MissionEnterPage2(void) {
    Ov008_SweepElements((int *)((char *)data_ov008_02090fa4 + 8));
    Ov008_LoadLayoutResource((int)((char *)data_ov008_02090fa4 + 8), (int)&gOv008UiMltMltgpPath);
    Ov008_MissionRetargetCellByTag(0, 0, 0);
    Ov008_MissionRetargetCellByTag(2, 0, 0);
    Ov008_Menu_SetupSprites(*(int *)((char *)data_ov008_02090fa4 + 0x94f4));
    Ov008_MissionBuildScreenCells(*(int *)((char *)data_ov008_02090fa4 + 0x94f4));
    Ov008_MissionRequestStateChange(3, 0, 0, 0, 0);
}
