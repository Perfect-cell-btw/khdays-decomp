/* Applies the temporary fields to the entry with the tag. */

extern int Ov008_FindEntryByTag(int arg0, unsigned int arg1);
extern void Ov008_ApplyTempFieldsAndRestore(int arg0, int arg1, int arg2, int arg3);

void Ov008_ApplyTempFieldsByTag(int arg0, int arg1, int arg2, int arg3)
{
    Ov008_ApplyTempFieldsAndRestore(arg0, Ov008_FindEntryByTag(arg0, (unsigned short)arg1), arg2, arg3);
}
