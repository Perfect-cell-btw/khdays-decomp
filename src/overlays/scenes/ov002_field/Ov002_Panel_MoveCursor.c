/* Forward to Ov002_PanelApplyCursorMove with the byte at *global as the first arg. */
extern int Ov002_PanelApplyCursorMove(int val, int arg);
extern int data_ov002_0207f620;

int Ov002_Panel_MoveCursor(int param_1) {
    return Ov002_PanelApplyCursorMove(*(unsigned char *)*(int *)&data_ov002_0207f620, param_1);
}
