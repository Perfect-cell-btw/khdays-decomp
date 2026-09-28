extern void Ov002_SubmitEnabledRowMask(void);
extern char *data_ov002_0207fa10;
/* Set widget `idx`'s state byte, returning the previous value; optionally re-layout. */
int Ov002_SetWidgetStateByte(int idx, int value, int relayout) {
    int table = *(int *)((int)data_ov002_0207fa10 + 4);
    char *p = *(char **)(table + idx * 4 + 4);
    int old = *p;
    *p = value;
    if (relayout != 0) {
        Ov002_SubmitEnabledRowMask();
    }
    return old;
}
