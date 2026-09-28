/* Ov008_SetTagValueDup -- push (param_3,param_4) to the widget bound to tag param_2
 * (Ov008_ApplyTempFieldsAndRestore). Resolves the tag entry via Ov008_FindEntryByTag (called twice, as the ROM
 * does; the first result is unused). */
/* Defined taking tag as unsigned int: declared narrower here, which is what makes mwcc truncate the
 * argument at the call as the ROM does (declared as defined, the code comes out different). */
extern int  Ov008_FindEntryByTag(int owner, unsigned short tag);
/* Defined taking a as int, b as int: declared narrower here, which is what makes mwcc truncate the
 * argument at the call as the ROM does (declared as defined, the code comes out different). */
extern void Ov008_ApplyTempFieldsAndRestore(int owner, int entry, unsigned short a, unsigned short b);

void Ov008_SetTagValueDup(int param_1, unsigned int param_2, unsigned short param_3, unsigned short param_4) {
    Ov008_FindEntryByTag(param_1, param_2);
    int entry = Ov008_FindEntryByTag(param_1, param_2);
    Ov008_ApplyTempFieldsAndRestore(param_1, entry, param_3, param_4);
}
