/* Selects shortcut `shortcut` (0-3: A, X, Y, B pressed with the shortcut button held, see
 * Ov022_UpdateCommandInput): when Ov002_Panel_GetField10 accepts it, the deck's row is taken from
 * the cursor and the panel's mode (+0x1a4) becomes 7; otherwise the mode is what
 * Ov002_PanelResolveGroupRow gives for it. */
extern int Ov002_Panel_GetField10(int shortcut);
extern void Ov002_PanelAssignRowFromCursor(int shortcut);
extern int Ov002_PanelResolveGroupRow(int shortcut);

extern char *data_ov002_0207f614;

void Ov002_SelectShortcut(int shortcut) {
    char *ctx = data_ov002_0207f614;

    if (Ov002_Panel_GetField10(shortcut) != 0) {
        Ov002_PanelAssignRowFromCursor(shortcut);
        *(short *)(ctx + 0x1a4) = 7;
    } else {
        *(short *)(ctx + 0x1a4) = (short)Ov002_PanelResolveGroupRow(shortcut);
    }
}
