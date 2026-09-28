extern void Ov002_BuildTileRow(void);
extern void Ov002_HandlePanelInput(unsigned int kind, int arg);
extern char *data_ov002_0207f620;
/* If the HUD context is live, rebuild its tile row and refresh the local player's sub-updater. */
void Ov002_HudRefreshPlayer(void) {
    int ctx = (int)data_ov002_0207f620;
    if (ctx != 0) {
        Ov002_BuildTileRow();
        Ov002_HandlePanelInput(*(unsigned char *)(ctx + 1), -1);
    }
}
