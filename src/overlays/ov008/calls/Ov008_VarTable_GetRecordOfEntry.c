extern void Ov008_GetVarRecordByIndex(void *, unsigned short);
void Ov008_VarTable_GetRecordOfEntry(void *arg0, char *arg1)
{
    Ov008_GetVarRecordByIndex(arg0, *(unsigned short *)(arg1 + 4));
}
