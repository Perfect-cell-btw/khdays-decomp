extern void Ov002_HandlePanelInput(int id, unsigned int arg);
extern void Ov002_PanelApplyCursorMove(unsigned int kind, int flag);
extern char *data_ov002_0207f620;
/* HUD reset: run the two sub-updaters (id 0 with arg, and kind = ctx's first byte with flag 0),
 * then clear the ctx word at +0x10. */
void Ov002_HudReset(unsigned int arg) {
    int ctx = (int)data_ov002_0207f620;
    Ov002_HandlePanelInput(0, arg);
    Ov002_PanelApplyCursorMove(*(unsigned char *)ctx, 0);
    *(int *)(ctx + 0x10) = 0;
}
