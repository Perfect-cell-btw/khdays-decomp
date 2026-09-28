/* Script command: when ready stores the selection and applies it; returns 1. */

extern int IsSubStructValidAndReady(void);
extern void SetSelectionIfChanged(unsigned a);
extern unsigned char data_020425e8;

int ScriptCmd_SetSelection(int param_1, int param_2) {
    if (IsSubStructValidAndReady() == 0) {
        data_020425e8 = param_2;
        SetSelectionIfChanged(param_2 & 0xff);
        return 1;
    }
    return 0;
}
