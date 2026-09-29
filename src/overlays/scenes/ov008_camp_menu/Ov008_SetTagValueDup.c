/* Ov008_SetTagValueDup -- push (param_3,param_4) to the widget bound to tag param_2
 * (Ov008_ApplyTempFieldsAndRestore). Resolves the tag entry via Ov008_FindEntryByTag (called twice, (unsigned short)(as the ROM
 * does; the first result is unused)). */
extern int  Ov008_FindEntryByTag(int owner, unsigned int tag);
extern void Ov008_ApplyTempFieldsAndRestore(int owner, int entry, int a, int b);

void Ov008_SetTagValueDup(int param_1, unsigned int param_2, unsigned short param_3, unsigned short param_4) {
    Ov008_FindEntryByTag(param_1, (unsigned short)param_2);
    /* Written as a mask where another call truncates with a cast: mwcc would otherwise compute the
     * truncation once and keep it, while the ROM truncates again at each call. */
    int entry = Ov008_FindEntryByTag(param_1, param_2 & 0xffff);
    Ov008_ApplyTempFieldsAndRestore(param_1, entry, (unsigned short)param_3, (unsigned short)param_4);
}
