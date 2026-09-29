/* Ov025_SetTagValueDup -- push (param_3,param_4) to the widget bound to tag param_2
 * (Ov025_ApplyTempFieldsAndRestore). Resolves the tag entry via Ov025_FindEntryByTag (called twice, (unsigned short)(as the ROM
 * does; the first result is unused)). */
extern int  Ov025_FindEntryByTag(int owner, unsigned int tag);
extern void Ov025_ApplyTempFieldsAndRestore(int owner, int entry, unsigned short a, unsigned short b);

void Ov025_SetTagValueDup(int param_1, unsigned int param_2, unsigned short param_3, unsigned short param_4) {
    Ov025_FindEntryByTag(param_1, (unsigned short)param_2);
    /* Written as a mask where another call truncates with a cast: mwcc would otherwise compute the
     * truncation once and keep it, while the ROM truncates again at each call. */
    int entry = Ov025_FindEntryByTag(param_1, param_2 & 0xffff);
    Ov025_ApplyTempFieldsAndRestore(param_1, entry, param_3, param_4);
}
