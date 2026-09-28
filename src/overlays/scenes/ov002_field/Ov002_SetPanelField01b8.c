/* Stores the panel's word at +0x1b8 and submits it to the field. */

extern int data_ov002_0207f614;
extern int Ov002_Field_SetBCAndSubmit();

int Ov002_SetPanelField01b8(int arg0) {
    *(int *)(*(int *)&data_ov002_0207f614 + 0x1b8) = arg0;
    return Ov002_Field_SetBCAndSubmit(arg0);
}
