/* Restores the panel's group rows when the panel exists. */

extern int data_ov002_0207f620;
extern int Ov002_PanelRestoreGroupRows();

void Ov002_Panel_RestoreRowsIfAny(void) {
    int p = *(int *)&data_ov002_0207f620;
    if (p != 0) {
        Ov002_PanelRestoreGroupRows(p);
    }
}
