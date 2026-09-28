extern char *data_ov008_02090fac;
extern void Obj_InvokeInnerVtable8(void *p, int a, int b, int c, int d);
extern int Ov008_GetVarRecordByIndex(void *p, int id);
extern void Ov008_DrawStringShadowed(void *dst, int src, int x, int y, int w, int h);

/* Redraws the title bar with the given caption. */
void Ov008_DrawTitleBar(int caption) {
    char *bar = *(char **)&data_ov008_02090fac + 0xc19c;
    Obj_InvokeInnerVtable8(bar, 0, 0, 0xb0, 0x10);
    Ov008_DrawStringShadowed(bar,
                        Ov008_GetVarRecordByIndex(*(char **)&data_ov008_02090fac + 0xc130, caption),
                        0xa9, 2, 4, 0x20);
}
