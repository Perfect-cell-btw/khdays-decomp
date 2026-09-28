/* Returns the UI context state byte (+0x11), or 0 without a context. */

extern int data_ov002_0207f60c;

int Ov002_Ui_GetState(void) {
    int p = *(int *)&data_ov002_0207f60c;
    return p == 0 ? 0 : *(unsigned char *)(p + 0x11);
}
