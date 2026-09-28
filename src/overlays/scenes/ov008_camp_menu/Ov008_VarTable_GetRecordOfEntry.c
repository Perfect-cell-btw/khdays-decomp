/* Record of the entry's variable index. Returns the record, or NULL when the index is out of range.
 */

extern void *Ov008_GetVarRecordByIndex(void *, unsigned short);
void *Ov008_VarTable_GetRecordOfEntry(void *arg0, char *arg1)
{
    return Ov008_GetVarRecordByIndex(arg0, *(unsigned short *)(arg1 + 4));
}
