/* Set the panel's mode halfword at +0x1a4: 7 when Ov002_Panel_GetField10 accepts
 * the request, otherwise whatever Ov002_PanelResolveGroupRow resolves it to. */
extern int Ov002_Panel_GetField10(int req);
extern void Ov002_PanelAssignRowFromCursor(int req);
extern int Ov002_PanelResolveGroupRow(int req);

extern char *data_ov002_0207f614;

void Ov002_SetPanelModeForRequest(int req) {
    char *ctx = data_ov002_0207f614;

    if (Ov002_Panel_GetField10(req) != 0) {
        Ov002_PanelAssignRowFromCursor(req);
        *(short *)(ctx + 0x1a4) = 7;
    } else {
        *(short *)(ctx + 0x1a4) = (short)Ov002_PanelResolveGroupRow(req);
    }
}
