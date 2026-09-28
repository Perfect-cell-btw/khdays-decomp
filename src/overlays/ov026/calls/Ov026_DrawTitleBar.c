extern char *data_ov026_02091368;
extern void Obj_InvokeInnerVtable8(void *p, int a, int b, int c, int d);
extern int Ov026_GetVarRecordByIndex(void *p, int id);
extern void Ov026_DrawStringShadowed(void *dst, int src, int x, int y, int w, int h);

/* Redraws the title bar with the given caption. */
void Ov026_DrawTitleBar(int caption) {
    char *bar = *(char **)&data_ov026_02091368 + 0xc19c;
    Obj_InvokeInnerVtable8(bar, 0, 0, 0xb0, 0x10);
    Ov026_DrawStringShadowed(bar,
                        Ov026_GetVarRecordByIndex(*(char **)&data_ov026_02091368 + 0xc130, caption),
                        0xa9, 2, 4, 0x20);
}
