/* Ov006_MissionEnterPage2 -- Mission Mode: enter menu page 2.
 * Resets the page's resource block at OBJ+8, reloads it from data_ov006_02056598, rebuilds
 * layer 0 and layer 2, re-applies the current Mission Mode sub-state (OBJ+0x94f4) to the model and
 * the text, and starts the page-3 entry animation. */
extern void Ov006_SweepElements(int *block);
extern void Ov006_LoadAndInitResourceSections(int block, int desc);
extern void Ov006_MissionRetargetCellByTag(int layer, int a, int b);
extern void Ov006_Menu_SetupSprites(int state);
extern void Ov006_MissionBuildScreenCells(int state);
extern void Ov006_MissionRequestStateChange(int anim, int a, int b, int c, int d);
extern int *data_ov006_02056664;
extern int  data_ov006_02056598;

void Ov006_MissionEnterPage2(void) {
    Ov006_SweepElements((int *)((char *)data_ov006_02056664 + 8));
    Ov006_LoadAndInitResourceSections((int)((char *)data_ov006_02056664 + 8), (int)&data_ov006_02056598);
    Ov006_MissionRetargetCellByTag(0, 0, 0);
    Ov006_MissionRetargetCellByTag(2, 0, 0);
    Ov006_Menu_SetupSprites(*(int *)((char *)data_ov006_02056664 + 0x94f4));
    Ov006_MissionBuildScreenCells(*(int *)((char *)data_ov006_02056664 + 0x94f4));
    Ov006_MissionRequestStateChange(3, 0, 0, 0, 0);
}
